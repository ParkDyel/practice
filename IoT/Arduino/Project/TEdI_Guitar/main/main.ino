/*
* 제목 : 아두이노 기타
* 작성 : ParkDyel
* 일자 : 2017. 11. 23
* 내용 : 아두이노로 기타를 만들기 위해
         SpotPot, LDR, Lazer, Speaker 등을
         활용하였습니다.
* 회로 : ldr과 spotPot은 pull-up 저항을 연결해주시고
        Lazer와 Speaker는 증폭회로를 구성하는 것이 좋을 것이요.
        회로 구성이 어렵다면 증폭 IC가 있으니 이를 이용하시오.
* 문제점 : 하나의 아두이노에서 기본적으로 하나의 tone 함수만 구현 가능하고,
          이를 위해 라이브러리를 이용하여 3개의 타이머를 활용할 수 있으나,
          결국 2개씩 나누어 활용해야 하는 것으로 판단된다. 
*/
#define pin_output_lazer {레이저 핀 번호}

// 회로 연결에 따라 핀번호를 입력하시오
const int pin_input_ldr[4] = {1번현 핀번호, 2번현 핀번호, 3번현 핀번호, 4번현 핀번호};
const int pin_input_spotPot[4] = {1번현 핀번호, 2번현 핀번호, 3번현 핀번호, 4번현 핀번호};
const int pin_output_speaker[4] = {1번현 해당 스피커 핀번호, 2번현 해당 스피커 핀번호, 3번현 해당 스피커 핀번호, 4번현 해당 스피커 핀번호};

register int read_ldr[4] = {0,0,0,0};
int read_spotPot[4] = {1023, 1023, 1023, 1023};

int value_scale[4]={0,0,0,0};

// 쉽게 말해서 어떤 음부터 어떤 음까지를 현에 할당한 것인지
// 코딩하는 것이오. 1현의 경우 미에서 솔#까지
// 2현의 경우 라에서 C까지... 이런식으로 말이오.
const int string_scale_start[4]={1현 음계의 시작점, 2현 음계의 시작점, 3현 음계의 시작점, 4현 음계의 시작점};
const int string_scale_end[4]={1현 음계의 끝점, 2현 음계의 끝점, 3현 음계의 끝점, 4현 음계의 끝점};

#define threshHold_ldr {해당}

void setup(){
  pinMode(pin_output_lazer, OUTPUT);
  
  for(int i=0; i<4; i++){
    pinMode(pin_input_spotPot[i], INPUT);
    pinMode(pin_input_ldr[i], INPUT);
    pinMode(pin_output_speaker[i], OUTPUT);
  }

  digitalWrite(pin_output_lazer, HIGH);
}

void loop(){
  get_input();
  get_scale();
  set_scale();
  set_speaker();
}
void get_input(void){
  /* 
  * 해당 현의 ldr에 입력이 들어왔는지 판단합니다.
  */
  for(int i=0;i<4;i++){
    if(analogRead(pin_input_ldr[i]) > threshHold_ldr){
      read_ldr[i] = 1;
    } else {
      read_ldr[i] = 0;
    }
  }
}
void get_scale(void){
  /* 
  * 입력이 들어온 현에 해당하는 spotPot의 값을 읽습니다.
  * 만약 해당 현에 입력이 들어오지 않았으면 1023으로 초기화합니다(pull-up).
  */
  for(int i=0;i<4;i++){
    if(read_ldr[i]){
      read_spotPot[i] = analogRead(pin_input_spotPot[i]);
    } else {
      read_spotPot[i]=1023;
    }
  }
}

void set_scale(void){
  /* 
  * 입력이 들어온 현에 해당하는 spotPot의 값을
  * 현에 해당하는 실제 음계로 변환합니다.
  */ 
  for(int i=0;i<4;i++){
    if(read_ldr[i]){
      /*
      * 이때 저항 값 변화에 따라
      * map 함수의 인자 위치를 변경할 수 있습니다.
      * 예를 들어 기타 헤드에 갈수록 값이 올라가는 경우
      * 일반적인 기타의 동작과 반대이기 때문에, 두번째 인자와 세번째 인자를
      * 바꾸는 등의 시도가 필요합니다.
      */
      value_scale[i] = map(read_spotPot[i], 0, 1023, string_scale_start[i], string_scale_end[i]);
    }
  }
}

void set_speaker(void){
  /*
  * 입력이 들어온 현에 해당하는
  * 변환된 음계값을 스피커에 출력합니다.
  */ 
  for(int i=0;i<4;i++){
    if(read_ldr[i]){
      /*
      * 현재는 4개의 스피커를 사용하고 있지만
      * 어떻게 하면 1개의 스피커를 사용하고도 구현할 수 있는지
      * 보다 많은 자료를 찾아보는 것이 좋을 것 같습니다.
      * 또한 보다 명확한 음을 출력하기 위해서 트랜지스터를 이용하기도 합니다.
      * 차후 개선점으로 생각하면 좋을 것 같습니다.
      * 아래 함수의 경우 정상적인 입력이 아닌
      * 죽은 입력이 살아있는 경우
      * 3인자 tone(pin, freq, duration)을 사용하여
      * 타이밍 제어할 수 있으나 좋은 방법인지는
      * 실제 테스트하면서 진행해봐야 알 것 같습니다.
      */
      tone(pin_output_speaker[i], value_scale[i]);
    }
  }
}