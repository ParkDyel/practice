# apiCalls

## mixin

- 컴포넌트에 결합되는 형태
- 필요한 곳에서만 쓸 수 있음

### global

- 생성되는 모든 컴포넌트에 결합되는 형태(치명적인 단점)
- 라이프 사이클을 고려하여 유의하여 사용해야 함

## plugIn

- 서비스에서 1회 생성됨

## Vuex Action

- 만약 apiCall이 mutation을 필요로 하지 않는다면 anti-pattern에 해당될 수 있음.

## vanila Script

- 플랫폼 종속성을 벗어남
- axios 설정은 프로젝트 내에서 전부 동일함
- 필요한 곳에서만 쓸 수 있음

## 참고 자료

[포스팅](https://itnext.io/anyway-heres-how-to-do-ajax-api-calls-with-vue-js-e71e57d5cf12)
