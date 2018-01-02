## 프로젝트 개발 일지

작성일자 : 2017.10.06
작성인 : RYUL
프로젝트명 : Arduino Spaghetti
문서번호 : 2017-IoT-A-RYUL-02-DOCUMENT-02


내용 : 검출부 구현
- ![image](https://bennthomsen.files.wordpress.com/2014/12/opticalinterrupter.png?w=584&h=285)
```
analogRead(phoroInterruptPin) > Thereshold
```

1. Thereshold 값은 회로의 전원 상태에 따라 변동될 수 있는 여지가 있으니 실험을 시작하기에 앞서 조정이 필요함.

2. 파장이 940nm인 소자를 사용하기 때문에 주변의 RF 통신에 대해 주의하여야 한다.

3. 주기 측정에 있어 로직 설계가 충분히 이루어져야 할 것으로 고려된다.


내용 : 프로그램 로직 설계
```
if(검출감지()){
  if(flag_주기시작){
    주기측정(begin)
  } else {
    주기측정(end){
      계산(주기){
        프로그램초기화()
      }
    }
  }
}
```
```

```
내용 : 함수형 설계

boolean isDetected = false;
boolean isDetecting = false;
boolean isDetectedOut = false;

void Detected(void);
void Detecting(void);
void DetectedOut(void);
void reportT(void);
void initFlag(void);
```

```
내용 : 프로그램 구현
```
2017-IoT-A-RYUL-02-CODE-02 참고
```