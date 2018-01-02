# Relay

## Description

  릴레이는 기존 스위치와는 다르게 자동으로 ON/OFF를 할 수 있게끔 해주는 전자부품이다.

  사용 예 : 원격제어 선풍기
## Circuit

![Pump Circuit](../manual/Circuit_Relay.png)




## Code
```
// 핀 선언부
// 회로에서 pin 13에 연결하였기 때문에 relay 변수를 1로 설정한다.
// int relay = 13;


void setup(){
  /* 결과 값을 확인하기 위해 시리얼 모니터를 사용할 것이므로
  * 시리얼 통신을 9600으로 설정하고 개설한다.
  */
  Serial.begin(9600);
  /* 시리얼이 객체가 생성될 때까지 기다린다.
  * 거의 사용되지 않는 코드이지만
  * 어떠한 것을 사용할 때 기본적으로 동작이 완료되는 것을 확인해야 한다는
  */ 의미로 코드를 작성했다.
  pinMode(relay, OUTPUT);// relay를 OUTPUT으로 설정한다.
}
void loop(){
  //relay를 ON으로 설정한다.
  digitalWrite(relay, HIGH);
  //relay를 OFF으로 설정한다.
  digitalWrite(relay, LOW);
}

```