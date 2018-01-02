/*
Title : 
by 
Date
Description
*/

//pin 선언부
//적외선 수신부를 A5에 연결한다.
const int readPin = A5;

//변수 선언부
//int형 변수 delaytime은 delay함수에서 사용한다.
//int형 변수 ThreshHold는 측정여부를 판단하는 임계값이다.
//long형 변수 before은 1회 측정 시작 시간을 저장하는 변수이다.
//long형 변수 period는 1회 측정 주기를 계산하여 저장한 변수이다.
int delayTime = 500;
int ThreshHold = 940;
unsigned long before = 0;
unsigned long period = 0;

//상수 선언부
//double형 변수 pi는 널리 알려진 원주율 3.14를 저장한 변수이다.
//double형 변수 len은 실험에 사용된 실을 길이 50cm를 저장한 변수이다.
double pi = 3.14;
double len = 0.5;

//flag 선언부
//flag isDetected는 주기의 시작을 측정하였을 때 set되는 flag이다.
//flag isDetecting은 물체에 대한 1회 측정을 유지 중일 때 set되는 flag이다.
//flag isDetectedOut는 물체에 대한 1회 측정이 끝났을 때 set되는 flag이다.
boolean isDetected = false;
boolean isDetecting = false;
boolean isDetectedOut = false;

//함수 선언부
//void형 함수 Detected는 주기의 시작이 측정되었을 때 상태를 변화시키는 함수이다.
//void형 함수 Detecting은 물체에 대한 1회 측정을 유지될 때 상태를 변화시키는 함수이다.
//void형 함수 DetectedOut는 물체에 대한 1회 측정이 끝났을 때 상태를 변화시키는 함수이다.
//void형 함수 reporT는 1회 측정에 대해 계산하여 시리얼 모니터로 출력하는 함수이다.
//void형 함수 initFlag는 1 cycle이 끝났을 때 프로그램을 초기화하는 함수이다.
void Detected(void);
void Detecting(void);
void DetectedOut(void);
void reportT(void);
void initFlag(void);

//아두이노 setup 함수
//readPin을 input으로 설정한다.
//Serial통신을 9600의 속도로 사용한다.
void setup()
{
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

//아두이노 loop함수
void loop()
{
  //임계값과 아날로그 신호값을 비교하여 물체가 감지되었는지 확인한다.
  if (analogRead(readPin) > ThreshHold) {
    //주기의 시작이 감지되었다면 함수 Detected을 호출하고 loop문을 종료한다.
    if (isDetected == false)
    {
      Detected();
      return;
    }
    //1회 주기의 끝이 감지되었을 때 함수 reportT를 호출하고 loop문을 종료한다.
    if (isDetectedOut == true)
    {
      reportT();
      return;
    }
    //물체에 대한 1회 측정이 유지될 때 함수 Detecting을 호출하고 loop문을 종료한다.
    if (isDetecting == false)
    {
      Detecting();
    }
    return;
  }
  //1회 주기 시작의 측정이 끝났을 때 함수 DetectedOut을 호출하고 loop문을 종료한다.
  if (isDetected)
  {
    //같은 상태에서 연속되 호출을 방지하고자 flag를 사용하였다.
    if (isDetectedOut == false) {
      DetectedOut();
    }
    return;
  }

  return;
}

void Detected(void) {
  //시간을 측정하여 변수 before에 할당한다.
  before = millis();
  isDetected = true;
  //Serial.println("Detected");
  //정확성을 위해 지연시킨다.(챗터링)
  delay(delayTime);
}
void Detecting(void)
{
  isDetecting = true;
  //Serial.println("Detecting");
}
void DetectedOut(void)
{
  //Serial.println("Detected Out");
  isDetectedOut = true;
}
void reportT(void)
{
  //period는 1회 주기의 시작과 끝의 차를 통해 단진자의 주기를 구한다.
  period = (millis() - before) * 2;
  // g=4*pi^2*l/T^2
  // 분모에 1000의 제곱을 하는 이유는 아두이노에서의 시간의 단위는 마이크로 단위이기 때문이다.
  float gravity = 4 * pi * pi * len * 1000 * 1000 / pow(period, 2);
  initFlag();
}
void initFlag(void)
{
  isDetected = false;
  isDetecting = false;
  isDetectedOut = false;
}