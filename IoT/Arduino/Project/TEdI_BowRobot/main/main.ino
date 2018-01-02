/*
* 인사하는 로봇
* ParkDyel
* 2017.12.07
*/

#include <Servo.h>          // 서보모터 제어 라이브러리 호출
#include <SoftwareSerial.h> // 시리얼통신 라이브러리 호출

#define pin_bt_tx 2
#define pin_bt_rx 3

#define pin_ultraSonic_trig 9
#define pin_ultraSonic_echo 8

#define pin_servo 10

#define time_delay_servo 60

SoftwareSerial btSerial(pin_bt_tx, pin_bt_rx);  //시리얼 통신을 위한 객체선언
Servo handServo;

void setup()
{
  pinMode(pin_ultraSonic_trig, OUTPUT);
  pinMode(pin_ultraSonic_echo, INPUT);
  
  handServo.attach(pin_servo);

  Serial.begin(9600);   //시리얼모니터
  btSerial.begin(9600); //블루투스 시리얼
}
void loop()
{
  if (get_distance() < 30) {
    Serial.println("Someting Coughed!");
    set_bt_write('s');
    for (int it = 0; it < 2; it++) {
      for (int angle = 10; angle < 90; angle = angle + 15)
        set_servo_angle(angle);
      for (int angle = 90; angle > 10; angle = angle - 15)
        set_servo_angle(angle);
    }
    set_servo_angle(90);
  }
}

long get_distance(void) {
  float duration, distance;
  digitalWrite(pin_ultraSonic_trig, HIGH);
  delay(10);
  digitalWrite(pin_ultraSonic_trig, LOW);

  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(pin_ultraSonic_echo, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠준다.
  distance = ((float)(340 * duration) / 10000) / 2;
  Serial.println(distance);
  return distance;
}

void set_servo_angle(int local_angle) {
  handServo.write(local_angle);
  delay(time_delay_servo);
}

void set_bt_write(char temp) {
  if (btSerial.available()){
    btSerial.write(temp);   // 시리얼 모니터 내용을 블루추스 측에 WRITE
                            // 가끔 수신 측에서 신호를 보내줘야만 BT가 정상 동작하는 경우가 있다.
                            // 원인을 규명해야 한다.
  }
}