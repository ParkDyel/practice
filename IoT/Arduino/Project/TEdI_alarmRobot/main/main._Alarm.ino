/*
* 알람로봇! - Interrupt Alarm
* ParkDyel
* 2017.12.07
*/
#include "pitches.h"

#define pin_trig 13
#define pin_echo 12

#define pin_buzzer 9

#define pin_ISR 2

volatile byte state = 0;

int melody[] = {
  NOTE_G7,NOTE_G7,NOTE_A7,NOTE_A7,NOTE_G7,
  NOTE_G7,NOTE_E7,NOTE_G7,NOTE_G7,NOTE_E7,
  NOTE_E7,NOTE_D7,NOTE_G7,NOTE_G7,NOTE_A7,
  NOTE_A7,NOTE_G7,NOTE_G7,NOTE_E7,NOTE_G7,
  NOTE_E7,NOTE_D7,NOTE_E7,NOTE_C7
};

int noteDurations[] = {
  4,4,4,4,4,
  4,4,4,4,4,
  4,4,4,4,4,
  4,4,4,4,4,
  4,4,4,4
};

int get_distance(int trigPin, int echoPin);           // 초음파 센서에 인식된 거리를 구한다.
void play_track(int melody[], int noteDurations[]);   // 주어진 melody와 noteDurations을 연주한다.
void set_alarm(void);                                 // alarm을 활성화/비활성화하기 위해 state 변수를 토글합니다.

void setup(){
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);

  pinMode(pin_buzzer, OUTPUT);

  pinMode(pin_ISR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin_ISR), set_alarm, RISING);

  Serial.begin(9600);
}

void loop(){
  while(state){
    play_track(melody);
  }
}

void set_alarm(void){
  state = !state;
  Serial.println("state");
}

int get_distance(int trigPin, int echoPin){
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  return distance;
}

void play_track(int melody[], int noteDurations[]){
  for (int thisNote = 0; thisNote < 26; thisNote++)
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(pin_buzzer, melody[thisNote], noteDuration); //소리를 낸다.
    int pauseBetweenNotes = noteDuration * 1.30;      //delay 계산식
    delay(pauseBetweenNotes);                         //delay
    if(get_distance(pin_trig, pin_echo) > 30){
      state = 0;
      Serial.println("Stop");
      break;
    }
    noTone(pin_buzzer);                            //대상핀 출력 중단
    Serial.println(thisNote);
  }
}
