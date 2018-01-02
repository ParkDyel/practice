# DotMatrix 8X8 I2C MAX7219

## Description

  교육용으로 많이 사용되는 DotMatrix 8x8은 더 많은 갯수의 LED를 제어하기 전에 좋은 학습용 모듈이다.
  회로연결의 편의성 및 포트 효율성을 위해 I2C를 사용하는 방법에 대해 소개하고자 한다.
  실제 산업에서도 다양한 형태로 사용되었으나 현재는 많은 부분 높은 해상도의 LCD로 대체되고 있는 것으로 판단된다.

## Link
  [Manual](http://playground.arduino.cc/Main/LedControl)
  [Library](https://github.com/wayoda/LedControl)

## Circuit

  이번 MD 파일에서 소개하고자 하는 모듈은 I2C 통신이 가능하도록 모듈화된 DotMatrix(8X8)이기 때문에 회로는 매우 단순하다.

![DotMatrix Circuit](../manual/Circuit_DotMatrix8X8I2CMAX7219.png)

## Code
 위 모듈을 사용하기 위해서는 라이브러리를 필요로 하기 때문에
 아두이노 IDE에 라이브러리를 추가하도록 한다.

[Adafruit dht-sensor-library](https://github.com/adafruit/dht-sensor-library)

DHT 센서를 위한 여러 라이브러리들이 존재하지만 위 라이브러리는 DHT11, DHT21, DHT22를
모두 사용할 수 있기 때문에 위 링크를 남겼고
명확한 모델을 정한 경우 코드를 좀 더 가볍게 하고 싶다면 전용 헤더파일 DHT11.h 등을
사용할 수 도 있다.

위 링크에서 압축파일을 다운로드 받은 후 [Arduino IDE]-[스케치]-[라이브러리 포함하기]-[.zip 라이브러리 포함하기]를 눌러서 라이브러리를 추가해야 한다.

또한 dht-sensor-library는 Adafruit Unified Sensor 라이브러리를 포함하기 때문에 [Arduino IDE]-[스케치]-[라이브러리 관리] 에서 해당 라이브러리를 검색하여 설치하도록 한다.

라이브러리에서 제공하는 기본 예제 파일을 살펴보기 위해 [파일]-[예제]에서 해당 라이브러리의
하위 목록에서 적당한 예제파일을 연다.

```
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

//신호선과 연결된 디지털 핀 번호를 치환한다.
#define DHTPIN 2     // what digital pin we're connected to

/* 자신의 DHT 모델명의 코드를 주석해제하고
* 나머지 DHTTYPE은 주석처리한다.
*/
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  /* 결과 값을 확인하기 위해 시리얼 모니터를 사용할 것이므로
  * 시리얼 통신을 9600으로 설정하고 개설한다.
  */
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  /*DHT를 다루기 위해 dht 객체를 생성한다.
  */
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  /* 값이 정상적으로 읽어졌는지 확인하기 위해
  * isnan 함수를 사용하여 h와 t, 그리고 f 값에
  * 정상적인 숫자가 들어갔는지 확인한다.
  */
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
```

