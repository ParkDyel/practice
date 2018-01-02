# 실험일지

실험일자 :
수행인 : 

## 실험목표

  단진자 운동을 이용하여 중력 가속도를 알아보도록 한다.

## 기반지식

## 기구부 설계
1. 고정부
철제 스탠드와 철제 스탠드의 길이를 고려하여 60cm 길이의 실, 식의 단순화를 위하여 50g의 추를 준비한다. 실을 묶어 추를 철제 스탠드에 고정하는데 이때, 정치했을 때의 추의 위치는 검출부에서 인식되는 위치여야 하고 측정부와 중심점까지의 거리는 식의 단순화를 위해 50cm이어야 한다.

2. 측정부
물체를 측정할 수 있는 센서의 종류에는 적외선 센서와 이를 활용한 포토 인터럽트, 초음파 센서, 모션 감지 센서 등이 있다. 그 중 쉽게 접근할 수 있는 센서는 적외선 센서와 포토 인터럽트, 초음파 센서이다. 이 중 초음파 센서는 오차가 발생할 가능성이 보다 크고 포토 인터럽트는 정해진 규격을 따라야 하는 제한 때문에 적외선 센서를 이용하여 다음 회로를 참고하여 측정모듈을 구성하였다.

## 프로그래밍 설계

boolean isDetected = false; // 주기의 시작을 측정하였을 때 set되는 flag이다.
boolean isDetecting = false; // 물체에 대한 1회 측정을 유지 중일 때 set되는 flag이다.
boolean isDetectedOut = false; // 물체에 대한 1회 측정이 끝났을 때 set되는 flag이다.

void Detected(void); // 주기의 시작이 측정되었을 때 상태를 변화시키는 함수
void Detecting(void); // 물체에 대한 1회 측정을 유지될 때 상태를 변화시키는 함수
void DetectedOut(void); // 물체에 대한 1회 측정이 끝났을 때 상태를 변화시키는 함수
void reportT(void); // 1회 측정에 대해 계산하여 시리얼 모니터로 출력하는 함수
void initFlag(void); // 1 cycle이 끝났을 때 프로그램을 초기화하는 함수

## 프로그래밍 코드

  참고 : 2017-IoT-A-RYUL-02-CODE-02.ino

## 실험결과
<1차:보다 진폭이 작은 경우>
```
gravity:9.75
gravity:9.83
gravity:9.83
gravity:9.62
gravity:9.59
gravity:9.78

<2차:보다 진폭이 큰 경우>
gravity:9.92
gravity:9.59
gravity:9.86
gravity:9.72
gravity:9.67
gravity:9.83
gravity:9.64
gravity:9.86
gravity:9.75
gravity:9.67
gravity:9.86
gravity:9.75
gravity:9.95
gravity:9.78
```

## 결과 해석

 Theta가 1에 수렴되면 sin(Theta)가 Theta에 수렴된다는 가정으로 유도하였는데 진폭이 큰 경우를 실행하여도 진폭이 작을 때와 유사한 데이터 군집을 얻을 수 있었다.