##Grammer

### Execution Context(실행 영역)

Context라 부르기도 하는 Execution Context는 스크립트가 실행되면서 생성(Global Context)되거나 Function Call에 의해 생성(Active Context) 된다. 각각의 Active Context들은 Function Call에 의해 생성되며 생성된 순서대로 Stack 메모리에 삽입되게 되고, Stack의 FILO 원리대로 현재 실행중인 Context는 Stack의 최상위에 위치하게 된다. 각각의 Context는 언제나 Variable Environment, Lexical Environment, 그리고 ThisBinding 속성, 총 3개의 부분으로 구성되 있다. 그리고 3 속성 모두 Object 형식(자바스크립트의 Object 자료형으로 저장되는게 아니여서 사용자가 Access 할 방법은 전혀 없다)으로 저장된다.

 - Lexical Environment Object

구성 환경 객체는 해당 Context에서 선언된 변수/함수들의 Reference 값을 저장하는 객체이다. _내부 구성은 Variable Environment Object 에 저장된다_. Identifiers(변수/함수이름)을 Reference(메모리 참조값)으로 변환할 때 사용된다. Execution Context의 생성 초기시점에는 Variable Environment Object와 정확히 같은 값을 가지나, Context 내부에서 Scope Augmentation이 실행될 시, Variable Environment Object와는 달리 새로운 Identifier 와 그의 Reference 값이 추가된다.

 - Variable Environment Object

Lexical Environment에 포함되는 개념이나, 위에서 설명한 Lexical Environment Object가 생성 후에 내부 값이 변할 수 있는 것과 달리 Variable Environment Object는 내부에서 선언된 Variables, Function Declarations, Formal Parameters들을 저장하기 때문에 Hoisting 등 this 키워드를 이용한 Expression에 의해 새로운 변수/함수가 등장하더라도 절대로 값이 변하지 않는다.

 - ThisBinding Object

ThisBinding 객체는 해당 Execution Context의 this 키워드의 반환 값을 저장한다. Execution Context에서 사용자가 유일하게 접근가능하다. 참고로 this 키워드는 현재 Context가 참조하고 있는 객체를 가리키며 어떻게 함수가 호출되었냐에 따라 갈린다


당연하겠지만, Execution Context 내부의 모든 코드가 실행이 완료된 후에는, Execution Context는 Stack에서 삭제되며, 그와 관련된 Lexical Environment Object, Variable Environment Object, ThisBinding Object 모든 구성 환경 값들 또한 삭제된다.

Global Context는 최상위이자 가장 밖의 Execution Context로 function 외부에서 선언된 모든 함수들과 변수들이 이에 포함된다.

웹 브라우져 환경에서 Global Context의 Variable Environment Object는 Window Object이며체, Global Context에서 선언된 함수들과 변수들은 모두 Window Object에 저장된다.이 Execution Context 내부의 모든 코드가 실행이 되고 난 후에는, Window Object에서 삭제되고, 그 안에 저장된 함수들과 변수들 또한 파괴된다. Window Object 위의 Global Context는 웹페이지가 종료 되고 난 후에야 파괴된다.

[참고](https://muckycode.blogspot.kr/2015/03/javascript-execution-context-scope.html)

### hoisting

#### 선행지식 : Execution Context

Hoisting는 선언 코드의 경우 코드가 비록 뒤에 있다 하더라도 변수 또는 함수들이 해당 Scope에서 최상위에 위치하는걸 뜻한다.
자바스크립트엔진은 해당 Execution Context의 생성시, 즉 Runtime 시점에서 변수선언문이나 함수선언문을 읽기 전에 선언된 변수와 함수들을 다른 무엇보다도 먼져 읽어 Scope의 최상위에 위치시킨다. 이 덕에, 훨씬 뒤에서 선언된 함수들과 변수들을 그 전에 사용이 가능하다.

   * 참고로 변수의 경우에는 변수 선언(Variable Declaration)만 Hoisting 된다, 즉 Variable Initialization이 있다면 변수가 선언은 되나, 변수에 어떤 값도 들어가지 않는다는 뜻.

   * 또한 함수의 Execution Context의 생성은 함수 호출시 이뤄지므로, 함수 내부에서 선언된 변수들은 함수 호출시에서야 Hoisting 된다.

```
{
  function test1() {
    function internalFunction() {
      return true;
    }

    return internalFunction();

    function internalFunction() {
      return false;
    }
  }
  console.log(test1());

  function test2() {
    var internalFunction = function() {
      return true;
    }
  
    return internalFunction();

    var internalFunction = function() {
      return false;
    }
  }
  console.log(test2());

  function test3() {
    return internalFunction();

    var internalFunction = function() {
      return true;
    }

    var internalFunction = function() {
      return false;
    }
  }
  console.log(test3());

  function test4() {
    var internalFunction = function() {
      return true;
    }

    return internalFunction();

    function internalFunction() {
      return false;
    }
  }
  console.log(test4());
}
```

```
{
  test1 = false
  test2 = true
  test3 = TypeError: undefined is not a function
  test4 = true
}
```

[참고](https://muckycode.blogspot.kr/2015/02/javascript-hoisting.html)

## TOOL

## TEST 

### MOCHA
[참고](http://programmingsummaries.tistory.com/383)