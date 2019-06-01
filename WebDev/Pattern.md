# Pattern

2018.12.03

## 1. MVC

- 프로그램의 데이터에 관련된 Model
- 사용자 인터페이스인 View
- 상호 처리 로직을 담당하는 Controller

Controller로 사용자 입력이 들어오면, Model에게 수정사항을 알려주고, Model은 변경된 데이터를 참조하는 View에 전달합니다.

View와 Model이 의존적이기 때문에 상호 의존성을 줄이는 것을 프로그래밍 목표로 한다.

### MVC1 vs MVC2

___Java를 잘 모르는 개발자라 인터넷에서 찾기만한 패턴이다.___

MVC1의 경우 JSP가 MVC를 모두 담당하기에 유지보수가 어려운 반면, MVC2의 경우 servlet에 C를 담당하고 JavaBean이 M을, JSP가 V를 담당한다. MVC1과 MVC2를 비교했을 때 구조 설계 시간과 유지보수 시간을 고려하여 간단한 프로젝트에서는 MVC1, 중장기 중규 이상의 프로젝트에서는 MVC2가 적합할 수 있다.

## 2. MVP

- 프로그램의 데이터에 관련된 Model
- 사용자 인터페이스인 View
- View와 Model 사이에서 필요한 데이터를 Model로부터 가져와 가공하여 View에 전달하는 Presenter

Present가 View와 Model 사이의 가교 역활을 수행하면서 MVC의 단점인 View와 Model 사이의 의존성을 제거합니다.

View에 사용자 입력이 들어오면 Presenter에게 전달하고 Presenter는 Model에 데이터를 전달받아 처리한 후 View에 입력의 처리결과를 전달합니다.

하지만 이러한 구조는 View와 Presenter가 1:1로 서로 강한 의존성을 가집니다.

## 3. MVVM

- 프로그램의 데이터에 관련된 Model
- 사용자 인터페이스인 View
- View를 표현하기 위해 만들어진 View를 위한 Model

[커맨드 패턴](https://ko.wikipedia.org/wiki/%EC%BB%A4%EB%A7%A8%EB%93%9C_%ED%8C%A8%ED%84%B4)과 데이터 바인딩을 이용하여 구현합니다.

View에 입력이 들어오면 ViewModel에 커맨드 패턴으로 명령합니다. VM은 필요한 데이터를 Model에 요청하여 받은 데이터를 가공하여 저장합니다. 이때 View와 VM은 Data Binding으로 엮여 있기 때문에 자동으로 갱신됩니다.

## __참조목록__

[마기의 개발 블로그](https://magi82.github.io/android-mvc-mvp-mvvm/)