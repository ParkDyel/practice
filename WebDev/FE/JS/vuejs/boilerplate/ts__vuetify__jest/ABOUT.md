# ts\_\_vuetify\_\_Jest\_\_NightWatch

## Install

1. vue ui

   프로젝트를 간편하게 생성하기 위해 gui을 사용합니다.

   ```
   > vue ui
   ```

1. 프로젝트 위치

   원하는 위치에 프로젝트를 생성합니다.

1. 프리셋 설정

   필요한 옵션을 지정하기 위해 수동 모드로 진행합니다.

1. 필요한 기능들을 활성화합니다.

   - babel
   - TS
   - Router
   - Vuex
   - Linter/Formatter
   - Unit Testing
   - E2E Testing

1. 설정에서 필요한 기능들을 활성화합니다.

   - Use class-style component syntax
   - Use history mode for router?
   - Pick a linter / formatter config
     - TSLint
   - Pick a unit testing solution
     - Jest
   - Pick a E2E testing solution
     - Nightwatch(Selenium-based)

1. plug-in

   설치가 완료된 후, 플러그인 항목에 vuetify를 검색하고 설치합니다. 왠지 vue ui를 통해서 설치하면 더 오래걸리는 것 같은 느낌은 들지만 편리하지만 묵인하도록 합니다. 아직 vuetify에 대해 잘 모르기때문에 설정은 기본 값으로 진행합니다.

   [p.s](https://github.com/vuetifyjs/vue-cli-plugin-vuetify/issues/43)  
   하지만 실제로 ts 위에서 import를 하면 다음과 같은 에러가 발생한다.

   ```
   Try `npm install @types/vuetify` if it exists or add a new declaration (.d.ts) file containing `declare module 'vuetify/lib';`
   1 | import Vue from 'vue'
   ```

   이를 해결하기 위해 tsconfig.json 파일에 다음 코드를 추가한다.

   ```
   "compilerOptions": {
       "types": ["vuetify"],
   ```

   > 2 | import Vuetify from 'vuetify/lib'

## Component

1. package manager

   js에서 사용하는 package manager로는 크게 [npm](https://www.npmjs.com/)과 [yarn](https://yarnpkg.com/en/)이 있습니다.  
   npm은 배포가 쉽고 종속성을 쉽게 해결할 수 있는 package manager이지만 중복 설치가 되어 yarn과 비교하여 파일이 더 많고 속도가 더 오래걸리는 단점이 있다고 합니다.  
   하여 yarn으로 진행해볼까 했으나 이미 너무많은 것을 새로하기에 npm으로 진행했습니다.

1. babel

   bable은 ES6 이후의 문법들을 browser 별 동작을 보장하기 위해 오래된 버전의 문법으로 번역해준다.

1. ts

   JavaScript에 정적 타입 시스템을 도입하여 디버깅 시간을 감소시킬 수 있다라는 말에 도입하였다.  
   일부 코드의 양이 늘어나 생산성 저하를 우려하는 의견도 있으나 디버깅 시간이 감소하여 생산성 저하가 상쇄된다고 한다고 한다.

1. Linter/Formatter

   개인적으로 eslint + airbnb를 사용했으나 ts를 사용하면서 이번 프로젝트에서는 TSLint를 사용하고자 한다. 최근에 팀장님께서 Prettier를 소개해주셨지만 ts에는 tslint가 손쉬운 구성이 아닐까 해서 tslint 선택했다.

   [p.s](https://jsdev.kr/t/prettier/3161/2)  
   vscode용 prettier 플러그인 하고, JS쪽은 eslint-config-prettier TS쪽은tslint-config-prettier 적용해서 써요.
   그리고 vscode 옵션에

   ```
   "editor.formatOnSave": true,
   "tslint.autoFixOnSave": true,
   "eslint.autoFixOnSave": true,
   ```

   - ESLint
   - TSLint
   - Prettier

   p.s  
   컴파일러 끼리의 전쟁인지 저장할 대마다 수많은 warning을 만든다. 둘이 사이좋게 하기 위해 적절히 조율해준다. 개인적으로 singleQuote, no Tail을 좋아하기에 양쪽의 옵션을 조정해준다.

   p.s  
   하나의 프로젝트의 lint와 prettier를 사용하게 되면 수많은 옵션이 충돌된다. 각각을 비활성화하거나 옵션을 조정하기 위해서 각각 다음 링크를 참고한다.

   [TSLint](https://palantir.github.io/tslint/rules/)  
   [prettier](https://prettier.io/docs/en/options.html)

1) Unit Testing

   - Jset

1) E2E Testing

   - NightWatch

1) Use class-style component syntax

   - [ref](https://vuejs.org/v2/guide/typescript.html#Class-Style-Vue-Components)

1) Use history mode for router?
   - [ref](https://router.vuejs.org/guide/essentials/history-mode.html#example-server-configurations)

### TypeScript
