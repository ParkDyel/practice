## Google Protocol Buffer에 관하여

1. Protocol Buffer란?
    - Protocol buffers은 구글의 언어와 풀랫폼에 대해 중립적이며 구조화된 데이터를 직렬화하는 확장 가능한 메카니즘이다. XML과 같은 개념이지만 보다 작고, 빠르고, 단순하다. 데이터를 구성하는 방법을 한번 정의하면, 생성된 소스 코드를 사용하여 다양한 데이터 스트림과 언어에서 손 쉽게 사용할 수 있다.

2. 다른 Protocol
    - 기존의 개발되어 있는 XML 과 같은 방식을 이용하거나 사용자만의 프로토콜을 개발한다. 전자의 경우에는 그에 따른 장단점이, 후자의 경우에는 개발시간소요, 범용성, 재사용성 등에 단점이 있다.

3. Protocol Buffer와 다른 방식의 차이(장단점)
    - Binary 데이터 방식은 데이터 사이즈가 작고 송수신 처리시 성능을 보장해 줍니다. 또한 Binary 데이터이므로 데이터만 봐서는 무슨 의미인지 알 수가 없어 보안의 걱정도 덜 수 있습니다. 그러나 XML에 비해 보편화 되어 있지 않아 모든 플렛폼에서 사용할 수는 없고 Serialize/Deserialize 모듈 제공자에 큰 의존성을 갖습니다.
    - (장점) 상대적으로 20~100배 빠르지만 사용이 간단하고, 모호하지 않다. 또한 프로그램에서 사용 가능한 클래스를 생성해주고(C++/Java/Python 공식 지원), 최대 64MB 크기의 message까지 지원한다(성능 보장을 위한 제약). JSON 포맷 전환을 지원하며, BSD License 정책을 따른다.
    - (단점) repeat 사용시 serialize/parse 시 성능이 저하될 수 있으며, 데이터를 눈으로 확인할 수 없다 (Binary Data VS. Text Data). 표준 프로토콜이 아니므로 단말기/세톱박스 등 RTOS에서의 지원이 어렵다. 공식 지원 언어는 C++/Java/Python뿐이며 (proto3에서는 Go, Ruby, C#이 추가적으로 지원되고, 이외의 언어도 추가적으로 지원예정), Map/Set을 지원하지 안는다.

1..3 출처 [SK(주) C&C 블로그, 2013.02](http://skccblog.tistory.com/1011)
1..3 출처 [공식사이트](https://developers.google.com/protocol-buffers/)

4. C언어를 지원하는 protocol buffers 라이브러리는 여러 가지가 있는데, 이 중에서 nanopb를 사용하라고 한 이유가 무엇일까요? 
    - Nanopb는 Google's Protocol Buffers 데이터 포맷을 일반 C의 구현한 것이다. 32 bit microcontrollers를 타겟으로 하지만 작은 메모리(2-10 kB ROM, <1 kB RAM)를 가진 임베디드 시스템에도 적합하다. 보다 가벼운 Nonapb도 있다. 예를 들어, message와 field name을 코드에 저장하지 않아  introspection (searching a field by name)이 가능하지 않다. 클라이언트가 아두이노인 경우에는 적합한 라이브러리라고 판단할 수 있을 것 같다.

4 출처 [stackoverflow](https://stackoverflow.com/questions/3671275/is-there-a-good-c-implementation-of-google-protocol-buffers)

5. 예시로 주어진 요구사항에 맞는 프로토콜을 개발해봅시다.
    - 별첨문서
        - 요구사항
        - Python으로 개발된 proto 파일

6. 서버 환경에서 개발된 프로토콜을 이용하여 [전체 상태 점검 결과]\(클라이언트가 가진 모든 상태 데이터\)를 요청하는 데이터를 만들어봅시다.
    - 별첨문서
        - server.py
7. 서버 환경에서, [문제6]의 데이터가 정상적인지 확인해봅시다.

8. 클라이언트 환경에서, [문제6]의 데이터가 정상적인지 확인해봅시다.

9. 클라이언트 환경에서 개발된 프로토콜을 이용하여 [전체 상태 점검 결과]\(클라이언트가 가진 모든 상태 데이터\)를 반환하는 데이터를 만들어봅시다.

10. 클라이언트 환경에서, [문제9]의 데이터가 정상적인지 확인해봅시다.

11. 서버 환경에서, [문제9]의 데이터가 정상적인지 확인해봅시다.

5..11 참고 [니삼 블로그](http://nisam.tistory.com/7)

12. 데이터에 따라 Encoding 된 사이즈를 어떻게 예상할 수 있을까요?
    - API에서 제공되는 ByteSize(self)를 사용한다.
    - 데이터를 바이너리로 변환 시 128 Varint를 사용하므로 이에 따른 분석을 한다.

12 참고 [Google python reference](https://developers.google.com/protocol-buffers/docs/reference/python/google.protobuf.message.Message-class)

13. 통신망에서 패킷 사이즈를 16byte 이하로 제한하고 있다. 이에 맞추어 프로토콜을 수정합시다.(패킷 축소를 위해 Encode/Decode 전/후 추가적인 작업 수행 가능)
    - proto 파일 첨부
    - 추가 작업 설명
14. 통신망에서 패킷 사이즈를 10byte 이하로 제한하고 있다. 이에 맞추어 프로토콜을 수정합시다.(패킷 축소를 위해 Encode/Decode 전/후 추가적인 작업 수행 가능)

13..14 참고 [이글루스](http://egloos.zum.com/javawork/v/2726467)

15. 과제 수행 소감