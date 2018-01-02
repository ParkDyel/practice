# Soid Sensor

## Description

  Soil Moisture sensor는 흙 속 센서주변 습도의 변화에 따라 값이 바뀌는 센서이다.

  사용 예 : 자동 물주기 화분

## Circuit

![SMC Circuit](../manual/Circuit_soil_sensor.jpg)
![SMC Circuit](../manual/soil_moisture.jpg)

soil sensor에 주변 습도에 따라서 값을 입력 받는다. 
/*the sensor value description
0  ~300     dry soil
300~700     humid soil
700~950     in water */


## Code
```
// 핀 선언부
// 회로에서 A0에 연결하였기 때문에 SMCPin 변수를 A0로 설정한다.
int smcPin = A0;

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