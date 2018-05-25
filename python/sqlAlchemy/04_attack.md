1. engine
2. metadata
3. session
    - The Session is paying attention. It knows, for example, that Ed Jones has been modified. \
      세션이 ORM에 등록된 객체들을 살펴보고 있다고 한다. 변경된 경우 .new로 살펴볼 수 있다(dirty와 차이점은 무엇일까?). 

1. Session Open
2. filter
3. db change
4. filter