# Pump

## Description

  액체 펌프는 수중에 집어넣고 사용하며 모터를 이용하여 액체를 밀어낸다.

  사용 예 : 튜브와 연결하여 물을 높은 곳으로 보낸다.
## Circuit

![Pump Circuit](../manual/Circuit_LDR.png)

setSpeed()의 파라미터 값으로 뿜어져나오는 액체의 수압을 조절할 수 있다.


## Code
```
// 핀 선언부 
// 헤더파일 다운로드 경로: https://github.com/adafruit/Adafruit-Motor-Shield-library
// #include <AFMotor.h>
// 회로에서 pin 1에 연결하였기 때문에 motor 변수를 1로 설정한다.
// AF_DCMotor motor1(1);


void setup(){
  /* 결과 값을 확인하기 위해 시리얼 모니터를 사용할 것이므로
  * 시리얼 통신을 9600으로 설정하고 개설한다.
  */
  Serial.begin(9600);
  /* 시리얼이 객체가 생성될 때까지 기다린다.
  * 거의 사용되지 않는 코드이지만
  * 어떠한 것을 사용할 때 기본적으로 동작이 완료되는 것을 확인해야 한다는
  */ 의미로 코드를 작성했다.
  motor1.run(FOWARD);
  motor1.setSpeed(0); // 수중모터를 설정한다.
}
void loop(){
  /* analogRead 함수를 통해 A0의 값을 읽고 이를 println의 인자로 넘겨 출력한다.
  * analogRead(Pin)은 0~5V를 0~1023 값으로 반환한다.
  */
  Serial.println(analogRead(A0));
}

```