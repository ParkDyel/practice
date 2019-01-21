# Style Guide

이것은 Vue 코드에 대한 공식 스타일 가이드입니다. 프로젝트에서 Vue를 사용한다면,
// FIXME : bikeshedding
에러와 bikeshedding, 안티 패턴을 피하기 위한 좋은 레퍼런스입니다. 그러나 어떤 스타일 가이드도 모든 팀이나 프로젝트에 이상적일 수 없다고 생각하기 때문에, 경험, 기술 스택, 개인적인 가치에 기반하여 참고하세요.

대부분의 경우, 일반적인 JavaScript나 HTML에 대한 제안은 하지 않습니다. 세미 콜론이나 쉼표를 사용하는 지, HTML의 속성 값에 따옴표를 사용하는 지, 쌍따옴표를 사용하는 지도 관여하지 않습니다. 하지만 특정 패턴이 Vue의 Context에 유용한 경우에는 예외입니다,

## 항목

### Priority A : 필수

이 규칙은 에러를 예방하는데 도움이 되므로, 배우고 모든 곳에 적용하세요. 예외가 있을수 있지만 매우 드물고, JavaScript와 Vue에 대한 전문적인 지식이 있는 분들에 의해서만 만들어졌습니다.

### Priority B : 강력 추천

이 규칙은 대부분의 프로젝트에서 가독성 및 개발자 경험을 향상시킵니다. 이를 준수하지 않아도 코드는 실행되지만, 위반하는 경우는 드물어야 하고 좋은 핑계가 있어야 합니다.

### Priority C : 권장 사항

여러 가지 좋은 선택이 있는 경우 일관적이기위해 특정 선택을 할 수 있습니다. 이 규칙은 허용 가능한 각 선택을 설명하고, 기본 선택을 제안합니다. 즉, 일관성 있고 좋은 이유가 있다면 자신 만의 코드베이스 안에서 자유롭게 선택 할 수 있습니다. 좋은 이유를 가지세요! 커뮤니티 표준을 적용함으로 다음을 할 수 있습니다.

1. 발견한 커뮤니티 코드를 쉽게 파싱할 수 있도록 연습합니다.
2. 대부분의 커뮤니티 예제 코드를 수정 없이 복사하여 붙여넣을 수 있어집니다.
3. 당신이 선호하는 코딩 스타일에 익숙한 구직자를 자주 찾을 수 있습니다.

### Priority D : 주의 하여 사용

Vue의 일부 기능은 드문 edge case를 수용하기 위해 존재하고, 원활히 legacy 코드로부터 migration하기 위해 존재합니다.

그러나 지나치게 많이 사용하면 코드 유지 관리가 어려워지거나, 버그를 야기할 수 있습니다.

이 규칙은 잠재적으로 위험한 기능에 빛을 비추며, 언제, 왜 피해야 하는지 설명합니다.

## Priority A Rules : Essential (Error Prevention)

### Multi-word component names

HTML 요소는 단일 단어로 구성되기 때문에, HTML요소와 총돌을 방지하기 위해 App 컴포넌트를 제외하고 모든 컴포넌트 명칭은 여러 단어로 구성되여야 합니다.

#### Bad

```javascript
Vue.component( ‘todo’, {
   // ...
})
```

```javascript
export default {
  name : ‘Todo’,
  // ...
}
```

#### Good

```javascript
Vue.component( ‘todo-item’, {
  // ...
})
```

```javascript
export default {
  name : ‘TodoItem’,
 // ....
}
```

### Component data

컴포넌트 **data** 는 반드시 함수이어야 합니다.
new Vue에서 사용되는 경우를 제외하고, 컴포넌트의 **data** 속성을 사용할 때에, 그 값은 반드시 object를 반환하는 함수이어야 합니다.

data가 object일 때, 컴포넌트의 모든 인스턴스가 함께 공유합니다. 예를 들어, 아래와 같은 TodoList 컴포넌트를 가정해봅시다.

```javascript
data : {
  listTitle : '',
  todos : []
}
```

우리는 이 컴포넌트를 재활용하여, 사용자가 쇼핑, 찜목록, 오늘의 선택 등 여러 목록을 관리하기 원합니다. 하지만 문제가 있습니다. 컴포넌트의 모든 인스턴스가 같은 data object 참고하기 때문에, 하나의 목록에서 제목을 바꾼다면 다른 모든 목록의 제목 또한 바뀌게 됩니다. 이것은 todo를 추가, 수정, 삭제 할때도 동일합니다.

대신에, 우리는 각 컴포넌트 인스턴스가 각자의 data만을 관리하길 바랍니다. 그렇게 하기 위해, 각 인스턴스는 반드시 고유한 data object를 생성해야 합니다. 자바스크립트에서는 함수에서 객체를 반환하면 수행할 수 있습니다.

```javascript
data: function(){
  return {
    listTitle : '',
    todos: []
  }
}
```

#### Bad

```javascript
Vue.component('some-comp', {
  data: {
    foo: 'bar'
  }
});
```

```javascript
export default {
  data: {
    foo: 'bar'
  }
};
```

#### Good

```javascript
Vue.component('some-comp', {
  data: function() {
    return {
      foo: 'bar'
    };
  }
});
```

```javascript
export default {
  data: function() {
    return {
      foo: 'bar'
    };
  }
};
```

```javascript
// 유일하게 존재하는 root Vue 인스턴스에서 사용하는 경우 함수로 감싸지 않고 바로 객체를 사용해도 괜찮다.
new Vue({
  data: {
    foo: 'bar'
  }
});
```

### Props definition

가능한 자세히 prop를 정의해야 합니다.
발행된 코드에서, prop 정의는 가능한 자세해야 하며, 적어도 타입은 지정해주어야 합니다.

자세한 prop정의는 다음과 같은 두 이점이 있습니다.

- 이것은 컴포넌트의 API문서입니다. 즉, 어떻게 사용해야 하는지 알기 쉽습니다.
- 개발에 있어, compontents에 제공된 props의 형식이 다르다면 경고하기 때문에, 잠재적인 에러의 원인을 찾기 쉽게 도와줍니다.

#### Bad

```javascript
props: ['status'];
```

#### Good

```javascript
props: {
  status: String;
}
```

```javascript
props:{
  status: {
    type: String,
    required: true,
    // STUDY ME!!
    validator: function(value){
      return [
        'syncing',
        'synced',
        'version-conflict',
        'error'
      ].indexOf(value) !== -1
    }
  }
}
```

### Keyed **v-for**

**v-for**을 사용할 때는 반드시 **key**를 사용하세요.
**v-for**를 쓰는 경우 하위 트리의 내부 컴포넌트 상태를 유지하기 위해 **key**가 필요하다.
하지만 엘리먼트의 경우에도 애니메이션의 객체 불변성과 같은 예측 가능한 동작을 유지하는 것이 좋은 코드 습관입니다.

다음과 todo 배열을 가졌다고 생각해봅시다.

```javascript
data: function(){
  return {
    todos: [
      {
        id: 1,
        text: 'Learn to use v-for'
      },
      {
        id: 2,
        text: 'Learn to use key'
      }
    ]
  }
}
```

그런 다음 이것을 알파벳 순으로 정렬합니다. DOM을 갱신할 때, Vue는 가장 저렴한 DOM 변이를 수행하기 위해 렌더링을 최적화합니다. 즉, 첫 번째 todo 엘리먼트를 제거한 후, 목록 끝에 다시 추가 할 수 있습니다.

문제는 DOM에 남아있는 엘리먼트를 삭제하지 않는다는 것입니다. 예를 들어, transition-group을 사용하여 목록 정렬을 애니메이션으로 만들거나 렌더링된 요소가 input인 경우 포커스를 유지할 수 있습니다. 이 경우 각 항목에 고유한 키(예: key=todo.id)를 추가하면 Vue에게 직관적인 행동을 유도합니다.

경험에 의하면 항상 고유한 키를 추가하는 것은 더 좋으므로 이것에 대해 걱정할 필요가 없습니다. Object 불변성이 필요하지 않고 성능이 중요한 시나리오의 경우 특정한 예외를 만들 수 있습니다.

#### Bad

```javascript
<ul>
  <li v-for="todo in todos">
    {{ todo.text }}
  </li>
</ul>
```

#### Good

```javascript
<ul>
  <li
    v-for="todo in todos"
    :key="todo.id"
  >
    {{ todo.text }}
  </li>
</ul>
```

### Avoid **v-if** with **v-for**

**v-for** 를 사용하는 엘리먼트에 **v-if**를 절대 사용하지 마세요.

사용하고자 할 수 있는 두 가지 일반적인 경우가 있습니다.

- 리스트의 아이템을 정제(필터링)하기 위해 사용한 경우(예: v-for="user in users" v-if="user.isActive"), users를 정제된 리스트(예, activeUsers)를 갖는 새로운 computed속성으로 변경해야 합니다.
- 렌더링하지 않고 숨겨져야하는 리스트의 경우(예: v-for="user in users" v-if="shouldShowUsers", **v-if** 를 컨테이너 요소에 적용해야 합니다.

Vue가 지시자를 처리할 때, **v-for** 는 **v-if**보다 높은 우선순위를 가집니다. 그래서 다음과 같은 템플릿(Code 1) 이 있다고 가정할 때, 다음 코드(Code 2)와 같습니다.

```javascript
// Code 1
<ul>
  <li
    v-for="user in users"
    v-if="user.isActive"
    :key="user.id"
  >
    {{ user.name }}
</ul>
```

```javascript
// Code 2
this.users.map(function(users) {
  if (user.isActive) {
    return user.name;
  }
});
```

따라서, users의 일부만 렌더링하려해도, active users 세트의 변경 여부와 상관없이 다시 랜더링할때마다 목록 전체에 대해 연산을 반복해야 합니다. 대신에, computed속성에 연산을 반복하세요.

```javascript
//...
<ul>
  <li
    v-for="user in activeUsers"
    :key="user.id"
  >
    {{ user.name }}
  </li>
</ul>

//...
computed : {
  activeUsers: function() {
    return this.users.filter(function (user){
      return user.isActive
    }
  }
}
```

우리는 다음과 같은 장점을 가집니다.

- users 배열에 연관된 변화가 발생했을 때, 정렬된 리스트에 대해서만 재연산되어 정제(필터링)를 보다 효과적으로 만듭니다.
- v-for="user in activeUsers"를 사용하면, 렌더링하는 동안 active users에만 반복 연산하면 되어 렌더링을 보다 효과적으로 만듭니다.
- 보여주는 계층에서 로직이 분리되어, 보다 유지(change, extension of logic)하기 쉬워집니다.

업데이트 할 때도 유사한 장점을 가집니다.

```javascript
<ul>
  <li
    v-for="user in users"
    v-if="shouldShowUsers"
    :key="user.id"
  >
    {{ user.name }}
  </li>
</ul>
```

```javascript
<ul v-if="shuldShowUsers">
  <li
    v-for="user in users">
    :key="user.id"
  >
    {{ user.name }}
  </li>
```

**v-if**를 컨테이너 요소로 옮김으로 목록의 모든 user에 대해 shouldShowUsers에 대해 확인할 필요가 없습니다. 대신, 한번 확인하고 shouldShowUsers가 **false**라면 **v-for**를 확인하지 않습니다.

#### Bad

```javascript
<ul>
  <li
    v-for="user in users"
    v-if="user.isActive"
    :key="user.id"
  >
    {{ user.name }}
  </li>
</ul>
```

```javascript
<ul>
  <li
    v-for="user in users"
    v-if="shouldShowUsers"
    :key="user.id"
  >
    {{ user.name }}
  </li>
</ul>
```

#### Good

```javascript
<ul>
  <li
    v-for="user in activeUsers"
    :key="user.id"
  >
    {{ user.name }}
 </li>
</ul>
```

```javascript
<ul v-if="shouldShowUsers">
  <li
    v-for="user in users"
    :key="user.id"
  >
    {{ user.name }}
  </li>
</ul>
```

### Component style scoping

어플리케이션에서, 최상위층의 **App** 컴포넌트와 레이아웃 컴포넌트의 style은 전역 범위를 가지겠지만, 모든 컴포넌트의 style은 지역적 범위를 가져야 합니다.
이 룰은 싱글 파일 컴포넌트에만 연관되어 있습니다. **scoped** 속성을 사용하지 않고, CSS 모듈, BEM이나 다른 라이브러리/컨벤션을 통해 범위 지정을 할 수 있습니다. Component 라이브러리라고 해도, **scoped** 속성을 사용하는 것보다 클래스 기반의 전략을 사용하는 것이 낫습니다.
// CHECK
This makes overriding internal styles easier, with human-readable class names that don’t have too high specificity, but are still very unlikely to result in a conflict.
사람이 읽을 수 있는 클래스 이름을 사용하며 사용하는 것이 overfiting 되지 않으며 충돌이 나지 않고 더 쉽게 내부 스타일을 재정의 할 수 있게 합니다.

만약 큰 프로젝트에서 다른 개발자들과 개발하고 있거나 3rd-party HTML/CSS(예를 들어, Auth0)를 포함하고 있다면, 철저한 범위 지정은 스타일이 자신의 의도한 컴포넌트에만 적용되도록 합니다.

철저한 범위 지정가 지정된 속성 외에 고유한 클래스 이름을 사용하면 다른 3rd-pary CSS가 자신의 HTML에 적용되지 않도록 할 수 있습니다. 예를 들어, 많은 프로젝트는 button ,btn, icon라는 이름을 가진 클래스를 사용하므로 BEM과 같은 것을 사용하지 않아도 app에 특정되거나 컴포넌트에 특정된 접두사(예를 들어, ButtonClose-icon)를 추가하면 충동을 방지할 수 있습니다. 자신이 의도한 컴포넌트에만 적용되는지 확인하세요.

#### Bad

```javascript
<template>
  <button class="btn btn-close">X</button>
</template>
<style>
.btn-close {
  background-color: red;
}
</style>
```

#### Good

```javascript
<template>
  <button class="button button-cloase">X</button>
</template>

<style scoped>
.button{
  border: none;
  border-radius: 2px;
}

.button-close {
  background-color: red;
}
</style>
```

```javascript
<template>
  <button :class="[$style.button, $style.buttonClose]">X</button>
</template>

<style module>
.button {
  border: none;
  border-radius: 2px;
}

.buttonClose {
  background-color: red;
}
</style>
```

```javascript
<template>
  <button class="c-Button c-Button--close">X</button>
</template>

<style>
.c-Button {
  border: none;
  border-radius: 2px;
}

.c-Button--close {
  background-color: red;
}
</style>
```

### Private property names

// FIXME
플러그인, 믹스인 등에서 private 속성에 대해 prefix **\$\_** 를 사용하세요. 다른 사람이 작성한 코드와의 충돌을 방지할 수 있습니다. 또한 이름을 이용해 범위 지정을 하세요(예, **\$_yourPluginName_** ).

Vue는 소유한 private 속성을 정의하기 위해 prefix **\_** 를 사용합니다. 따라서 같은 prefix를 사용한다면(예, \_update), instance 속성을 overwriting할 위험이 있습니다. 만약 확인했고, 현재의 Vue가 particular 속성 이름을 가지지 않는다고 해도, 향후 버전과 충돌을 일으키지 않는다고 보장할 수 없습니다.

prefix **\$** 의 경우, Vue ecosystem에서 사용자에게 노출되기 위한 특수한 instance 속성이기 때문에 private속성으로 사용하는 것은 적절하지 않습니다.

대신, 위 두개의 prefix를 합쳐 **\$\_** 를 사용자가 정의한 private 속성에 사용하는 것을 권장하고, Vue와 충돌하지 않는 것을 보장합니다.

#### Bad

```javascript
var myGreatMixin = {
  // ...
  methods: {
    update: function() {
      // ...
    }
  }
};
```

```javascript
var myGreatMixin = {
  // ...
  methods: {
    _update: function() {
      // ...
    }
  }
};
```

```javascript
var myGreatMixin = {
  // ...
  methods: {
    $update: function() {
      // ...
    }
  }
};
```

```javascript
var myGreatMixin = {
  // ...
  methods: {
    $_update: function() {
      // ...
    }
  }
};
```

#### Good

```javascript
var myGreatMixin = {
  // ...
  methods: {
    $_myGreatMixin_update: function() {
      // ...
    }
  }
};
```
