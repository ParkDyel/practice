## Google Protocol Buffer
##### 이하 Proto

1. Protocol Buffer란?
    
    Protocol buffers은 Google에서 제공하는 언어와 풀랫폼에 대해 중립적인, 구조화된 데이터를 직렬화하는 확장 가능한 메카니즘이다. XML과 같은 개념이지만 보다 작고, 빠르고, 단순하다. 데이터 구조를 한 번 정의하면, 생성된 소스 코드를 사용하여 다양한 데이터 스트림과 언어에서 활용할 수 있다.

2. Protocol Buffer 차이점

    proto가 사용하는 Binary 데이터 방식은 데이터 사이즈가 작고 송수신 처리시 성능을 보장해 준다. 또한 Binary 데이터이므로 데이터만 봐서는 무슨 의미인지 알 수가 없어 보안성도 제공한다. 그러나 XML에 비해 보편화 되어 있지 않아 모든 플렛폼에서 사용할 수 없고 Serialize/Deserialize 모듈 제공자에 큰 의존성을 갖는다.

    - (장점) 상대적으로 가볍고 사용이 간단하고, 모호하지 않다. 또한 프로그램에서 사용 가능한 클래스를 생성해주고(C++/Java/Python 공식 지원), 최대 64MB 크기의 message까지 지원한다(성능 보장을 위한 제약). JSON 포맷 전환을 지원하며, BSD License 정책을 따른다.
    
    - (단점) repeat 사용시 serialize/parse 시 성능이 저하될 수 있으며, 데이터를 눈으로 확인할 수 없다 (Binary Data VS. Text Data). 표준 프로토콜이 아니므로 단말기/세톱박스 등 RTOS에서의 지원이 어렵다. 공식 지원 언어는 C++/Java/Python뿐이며 (proto3에서는 Go, Ruby, C#이 추가적으로 지원되고, 이외의 언어도 추가적으로 지원예정), Map/Set을 지원하지 안는다.

    ##### 참고 [SK(주) C&C 블로그, 2013.02](http://skccblog.tistory.com/1011)
    ##### 참고 [Google 공식사이트](https://developers.google.com/protocol-buffers/)

3. 개발환경 구성
    - Win OS
    - Linux
        - use apt
        ```
        $ sudo apt install protobuf-compiler -y
        $ sudo pip install protobuf
        ```
        - downloads from git
        1. [Git](https://github.com/google/protobuf/releases/)
        2. install step by step __releases/readme.md__


4. proto 파일 구성
```
 1: // protoc -I=./ --python_out=./ devicedata.proto
 2: // syntax="proto3";
 3: package iotProto;
 4:
 5: message Device {
 6:   required int32 temperature = 1;
 7:   required int32 ampereConsumption = 2;
 8:   required int32 battery = 3;
 9:   required int64 option = 4;
10:   required bool power = 5;
11: // optional string insertTime = 6 [default = "UNINSERTED"];
12: }
13:
14: message DeviceData {
15:   repeated Device device = 1;
16: }
```
_위 방식은 proto2 형식입니다. proto3의 경우 다음 [레퍼런스](https://developers.google.com/protocol-buffers/docs/proto3)를 참고하세요._
1. $ protoc -I=./ --python_out=./ devicedata.proto
    - protoc은 proto 파일을 언어 환경에 맞추어 파일을 생성해준다.
    - ex) protoc --proto_path=IMPORT_PATH --cpp_out=DST_DIR --java_out=DST_DIR --python_out=DST_DIR --go_out=DST_DIR --ruby_out=DST_DIR --objc_out=DST_DIR --csharp_out=DST_DIR path/to/file.proto
2. proto는 proto2와 proto3을 제공한다.
3. You can add an optional package specifier to a .proto file to prevent name clashes between protocol message types.
5. message {$name}
    - message에 대해 정의합니다.
6. {$fieldType} {$dataType} {$name} = {$tagId}
    - fieldTpye : 필수적인 required와 유무를 선택할 수 있는 optional, 배열과 같이 사용할 수 있는 repeated 값을 가질 수 있다.
    - dataTpye : field가 가질 Data Type을 지정한다. 이때 int32, int64, enum 등 다양한 type을 지정할 수 있다.([Google.protobuf.proto2.scalar_value_tpye](https://developers.google.com/protocol-buffers/docs/proto))
    - name : field의 이름을 지정한다.
11. [default = ""]
    - 해당 field의 초기값을 지정해줍니다.
15. repeated Device device = 1
    - message를 dataType으로 가지는 message를 정의한다. 
    - 이와 마찬가지로 message 내부에 message를 정의할 수 있다.
    - ex) message level_1{ message level_2 {}}
위 외에도 상황에 따라 reserve 키워드, extensions 기능 등이 제공된다.

5. python 사용
