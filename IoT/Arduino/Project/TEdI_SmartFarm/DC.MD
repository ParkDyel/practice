# DCMotorDrive

## Description
  모터의 제어를 위한 드라이버 모듈이다. 모터드라이버는 모터의 속도, 정방향, 역방향 회전 등을 아두이노의 프로그래밍을 통해 제어하게 된다.
  

  사용 예 : 자율주행 차

## Circuit

![LDR Circuit](../manual/Circuit_LDR.png)

LDR과 고변 저항의 위치 구성에 따라 밝을수록 값이 커지도록, 반대로 작아지도록 할 수 있다.


## Code
```
// 핀 선언부
// 회로에서 A0에 연결하였기 때문에 ldrPin 변수를 A0로 설정한다.
int ldrPin = A0;

void setup(){
  /* 결과 값을 확인하기 위해 시리얼 모니터를 사용할 것이므로
  * 시리얼 통신을 9600으로 설정하고 개설한다.
  */
  Serial.begin(9600);
  /* 시리얼이 객체가 생성될 때까지 기다린다.
  * 거의 사용되지 않는 코드이지만
  * 어떠한 것을 사용할 때 기본적으로 동작이 완료되는 것을 확인해야 한다는
  */ 의미로 코드를 작성했다.
  while(!Serial);
  // Serial에 특정 문자열을 출력하기 위해 다음과 같이 코드를 작성할 수 있다.
  // println 메소드와 print 메소드의 차이는 출력한 후 한 칸을 뛰는(\n) 여부 차이이다.
  Serial.println("Serial Open");
}
void loop(){
  /* analogRead 함수를 통해 A0의 값을 읽고 이를 println의 인자로 넘겨 출력한다.
  * analogRead(Pin)은 0~5V를 0~1023 값으로 반환한다.
  */
  Serial.println(analogRead(A0));
}

```

