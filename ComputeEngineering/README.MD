# Introduction to Computer Engineering
#### ParkDyel
#### 2018.06.11

## 소개
이 문서는 컴퓨터 엔지니어링, 컴퓨터 공학, 컴퓨터 과학 등으로 불리는 분야에 대해
작성자 스스로 정리하고 대략적으로 설명하기 위해 작성하였습니다.
부족한 작성자이다보니 내용이 사실과 다름이 있을 수 있습니다.
만약 발견하시고 첨삭 보내주시면 검토하고 바로 적용하겠습니다. 감사합니다.

#### 작성자 소개
글을 읽기전에 작성자에 대해 알면 글을 읽으실지 말지 판단하기 좋을것 같아 간단하게 제 스스로를 소개하겠습니다.
임베디드 개발자를 꿈꾸며 입문하였고 현재는 웹 개발자가 되기위해 열심히 노력하고 있습니다.
이 과정에서 세부 전공에 대해 많은 고민을 했고 그런분들에게 조금이나마 도움이 되면 좋을 것 같아 자료를 작성하기로 마음먹었습니다.
하지만 사실 해당 분야에서 시니어, 아니 주니어 조차 되보지 못했기 때문에 사실과 많이 다를 수 있다는 것을 참고해주시면 좋을 것 같습니다.
그리고 관련 분야의 주니어, 시니어분들이 많이 읽으셔서 이 글이 좀더 유익한 정보글이 되었으면 좋겠습니다.

## 내용

1. Programming
    - [Computer architecture](https://en.wikipedia.org/wiki/Computer_architecture)

        일반적으로 컴퓨터라고 불리는 기계는 HW와 SW로 이루어진다. 통상적으로 컴퓨터 아키텍쳐라고하면 HW 중에서도 CPU 위주의 설계를 말합니다.
        일반적으로 CPU는 제어장치, 연산장치, 기억장치 등으로 구성되어 있으며 데이터 송수신 버스를 통해 메모리와 같은 주변장치의 데이터에 접근합니다.

        ![컴퓨터 구조](https://sanjayachauwal.files.wordpress.com/2017/10/overall.gif)

        제어장치(CU)는 기계어를 분석하고 해당 명령어를 실행하기 위해 내부 HW 자원의 클럭, 실행 순서 등을 제어합니다. 연산 장치는 제어장치의 통제를 받아 컴퓨터 연산을 실행합니다. 대표적으로 가산, 싀프트, E-OR 등의 연산이 있습니다. 통상 연산 장치(ALU)가 한번에 처리할 수 있는 비트의 크기는 레지스터리(Registers)의 비트 수, 통신 버스의 병렬 처리 비트 수와 동일하며 이에 따라 CPU의 비트를 표기합니다. 종종 레지스터리 비트 수는 ALU가 처리할 수 있는 비트 수 보다 큰 공간을 가지고 있기도 합니다.

        이때 ALU의 피연산자를 가져오기 위해 RAM에 접근하기도 하고, 하드 디스크, 네트워크 등 그 외의 장치들에 접근하기도 합니다. 이때 접근속도를 높히기 위해 내부 Register, RAM, SDD, HDD와 같은 저장장치를 나누어 사용합니다. 저장장치를 적은 순서대로 비교적 속도는 빠르지만 장치의 가격이 비쌉니다.

        용도나 처리 용량에 따라 [Microcontroller(MCU, -Unit), PIC 등 다양한 이름](https://www.eetimes.com/author.asp?section_id=216&doc_id=1322856)으로 불리는 칩들은 결국 전자 회로를 제어하기 위해 사용되고, 엘리베이터에 들어가는 8-bit 부터 PC에서 사용되는 64-bit까지 일반적으로 위와 같은 구조를 기본 골격으로 합니다. 

        `(Low)` MCU의 제품 또는 제조사(또는 설계사)는 용도와 산업 분야에 따라 굉장히 다양합니다. 이미지 처리에 적합한 제품군(ISP, Image Signal Processor), 기본적인 기능을 제공하는 제품군, 많은 IO를 제어할 수 있는 제품군 등이 있습니다. 이에 따라 다양한 명칭으로 분류되고, 이 중 일반 사용자들이 사용할 기능들을 모아 제공하는 것이 가장 널리 알려진 인텔 CPU 군입니다. 작성자가 알고 있는 제조사는 Arduino에 사용되는 MCU를 생산하며 8-bit 강자, Texas Instruments‎, Freescale과 합병되고 퀄컴에 인수된 NXP, 모바일 AP를 생산하는 퀄컴, 범용 CPU의 강자 Intel, 그리고 경쟁사 AMD 등이 있습니다.

        이제 SW적인 측면으로 살펴보도록 합니다. ~~이러한 구조를 부르는 정확한 용어가 기억나지 않아 해당 분기에 내용을 같이 기술합니다.~~

        |계층|간단한 내용|
        |:--:|:--:|
        |응용 프로그램|사용자가 주로 접하는 M사의 Office, G사의 Broswer로 대표하는 사용자에게 필요하는 기능을 제공하는 프로그램입니다.|
        |OS|응용 프로그램이 원할히 구동될 수 있도록 자원관리(CPU, 메모리, 입출력 장치 등)를 하고 환경을 구성해주는 프로그램입니다.|
        |커널|OS와 HW 사이의 가교역활을 해주는 프로그램입니다. 아직까지는 사람이 읽을 수 있는 언어입니다.|
        |HW|실제로 구동되는 전자 부품들입니다. 전기적 신호로 동작합니다.

        근래에는 특정 환경을 구축해주는 가상 환경들도 위 레이어에 한 층을 차지 할 수 있지 않을 까 싶습니다. 대표적으로 Java의 구동 환경을 구성해주고, 아래의 시스템 호환성에 대해서 개발자가 고려하지 않도록 설계된 JVM이 있고, 여러 개발 환경을 편하게 구축할 수 있는 Docker가 있습니다.~~어느새 Virtual Machine은 생략한다.~~
        
    - Coding

        Coding이란 사전에 약속된 규정에 맞추어 원하는 동작을 실행하도록 코드를 작성하는 동작입니다. 각각의 언어마다, 심지어 언어의 버전과 컴파일러마다 세부 규정은 다를 수 있습니다. 예를 들어 C언어에서 반복문 for의 초기 지시자 선언 위치 제한이 생각나네요.
        ```
        case 1)
        int idx=0;
        for(i=0;idx<limits;idx++)
        ```
        ```
        case 2)
        for(int idx=0;idx<limits; idx++)
        ```
        ~~잘못 기억하는 건지 확실치 않네요 사실 중요한건 아니니깐요...라고 자기합리화?~~

        `(tweet)`기사를 보다보면 프로그래밍과 구분하지 않는 경우가 많은 것 같은데 개인적으로는 프로그래밍과 코딩을 구분해서 사용하는 것이 좋지 않을까 생각합니다. 지극히 제 생각에 프로그래밍은 프로그램을 설계하고 이를 작성하는 코딩을 포함하는 동작이고, 그에 반면 코딩은 프로그램을 동작시키기 위해 코드를 작성하는 것입니다.
    - Compile & Debug
        - Compile

        컴파일이란 사람이 읽을 수 있는 고급 언어로 작성된 코드를 실행시킬 수 있는 프로그램으로 변환시키는 과정을 말합니다. Compile은 때에 따라 위 과정 전체를 뜻하기도 하고 프로그램으로 변환시키는 과정 중 어셈블러로 변환하는 과정만을 뜻하기도 합니다. 후자로 해석되는 경우에는 Compiler-Assembler-linker를 통해 처리됩니다.

        다만 언어에 따라 Compile 대신 한 구문씩 실행하는 interpreter를 사용하기도 합니다. 대표적으로 python과 JavaScript가 있습니다.

        위 과정은 결국 작성한 코드를 기계가 이해할 수 있도록 번역을 해주는 과정이기 때문에 문법적인 오류를 검출 할 수 있습니다.

        - Debug

        초기의 컴퓨터가 이상작동을 할 때 회로에 있는 벌레를 치웠더니 정상동작 되더라라는 어원을 가진 디버그는 프로그램을 실행할 때 실시간으로 자원이나 코드 실행 순서를 추적하며 프로그램을 확인하는 과정입니다. 논리적인 오류를 검출하기 위해 사용됩니다.
    
    - Program & Process
        - Program
        
        코딩을 통해 작성된 특정 작업을 수행하기 위해 실행할 수 있는 파일을 뜻합니다.

        - Process
        
        프로그램이 운영체제 등에 의해 자원을 할당받고 실행되고 있는 상태를 말합니다.


2. Development Diversity
    - Diversity
        - Web Application Developer

        |DB|<->|Server|<->|Client(Browser)|||
        |:-:|:-:|:-:|:-:|:-:|:-:|:-:|
        |||||<||웹 퍼블리셔, 웹 디자이너|
        ||| < ||FE 개발자|
        | < ||BE 개발자|| > |
        |DBA||>|||

        브라우저에서 동작하는 프로그램을 개발하는 개발자로 통칭 웹 개발자라고 합니다. 세부 분야로는 back-end, front-end, 웹 퍼블리싱 등이 있고, 각각의 양 끝에는 DBA, 웹 디자이너 등이 있습니다. **back-end(Server) 개발자**는 front-end에서 화면을 출력하기 위해 필요한 자료들이나, 로그인 요청과 같은 로직을 처리하는 프로그램을 개발하고, **front-end(Client) 개발자**는 사용자에게 데이터나 정보를 제공하기 위해 웹 화면을 프로그래밍합니다. 이외에도 관련 직무로 데이터와 정보를 다루기 위한 데이터베이스 설계 및 운용사, 사용자에게 편리한 서비스를 제공하기 위한 웹 퍼블리셔/디자이너 등이 있습니다.

        - Application Developer
        
        - Emebeded Developer
        - DBA
    - OS
        - Windows
        - Linux(Unix)
        - Mac OS
    - Language
        - Compile vs MarkUp(Script)
        - C(UNIX), 절차형, 데니스 리치
        - Java(JVM, OOP), JSP, 제임스 고슬링
        - Python(함수형), 귀도 반 로섬
        - JavaScript(브라우저, 비동기), PHP, 브렌던 아이크
        - Ruby/Scala/Swift/Go/Kotlin

3. Coding
    - C
        - Variable and Function
    - Java
        - Object, Inheritance, class, Interface
    - JavaScript
        - Interpreting
        - Chrome Develomet tool
        - Node.js
        - Asyncronize & Syncronize
        - 
    - Python
        - list, Module
4. Grammer
    - for
    - while
    - switch-case
    - Recursive function
    - callback
    - Anonymous functions

5. Structure
    - Array
    - list
    - Stack
    - Queue
    - HashTable(Dictionary, JSON)
    - Tree
    - Sort
    - Graph

6. Data
    - File I/O
    - DataBase 
        - SQL
        - NoSQL
        - Cloude DataBase

7. Therad/Process
    - Multi-Process
    - Multi-Therad
    - IPC

8. NetWork
    - ISO 7 Layer
        - TCP/IP
        - HTTP
    - Web
        - HTML
        - DOM
        - Server
        - Incoding

9. Maker, OpenSource
    - Embedded
        - Arduino
            - AVR
        - RasbperryPi
            - ARM
    - OpenSource
        - Linux
        - License
        - Git/Github/GitDesktop

10. Web
    - Web Programming Component
    - HTML, CSS, JavaScript
    - Bitmap vs Vector, SVG
    - JavaScript Library(jQuery, D3.js)
    - jQuery
        - AJAX
    - View Engine
        - Angular
        - React
        - Vue.js
    - CSS
        - Bootstrap

11. Python:Extension
    - Django
    - Flask
    - sqlalchemy
    - Tensorflow

12. JavaScript:Extension
    - Electon
    - Node.js
    - MongoDB