#include <SoftwareSerial.h>

#define blueTx 2
#define blueRx 3
#define pin_motor_a_IN1 5
#define pin_motor_a_IN2 6
#define pin_motor_b_IN3 9
#define pin_motor_b_IN4 10

//int STATE_MOTOR_A_IN1 = LOW;
//int STATE_MOTOR_A_IN2 = LOW;
//int STATE_MOTOR_B_IN3 = LOW;
//int STATE_MOTOR_B_IN4 = LOW;

volatile char busket;

void set_motor_state(void);
void set_motor_forward(void);
void set_motor_backward(void);
void set_motor_turnleft(void);
void set_motor_stop(void);
void set_motor_stop_direciton(void);
//void set_motor(void);
void error(int errno, char errchar);

SoftwareSerial blueTooth(blueTx, blueRx);

void setup() {
  pinMode(pin_motor_a_IN1, OUTPUT); // 방향모터
  pinMode(pin_motor_a_IN2, OUTPUT);
  pinMode(pin_motor_b_IN3, OUTPUT); // 주행모터
  pinMode(pin_motor_b_IN4, OUTPUT);

  Serial.begin(9600);
  blueTooth.begin(9600);
}

void loop() {
  if (blueTooth.available()) {
    busket = (char)blueTooth.read();
    delay(10);
    Serial.println(busket);
  }
  set_motor_state();
//  busket = ' ';
}

void set_motor_state(void) {
  switch (busket) {
    case 'f':
      set_motor_forward();
      busket = ' ';
      Serial.println(busket);
      break;
    case 'b':
      set_motor_backward();
      busket = ' ';
      break;
    case 's':
      set_motor_stop();
      busket = ' ';
      break;
    case 'l':
      set_motor_turnleft();
      busket = ' ';
      Serial.println(busket);
      break;
    case 'r':
      set_motor_turnright();
      busket = ' ';
      Serial.println(busket);
      break;
    case 'c':
      set_motor_stop_direciton();
      busket = ' ';
      break;
    default:
      error(408, busket);
      break;
  }
  delay(25);
}

void set_motor_forward(void) {
  digitalWrite(pin_motor_b_IN3, LOW);
  digitalWrite(pin_motor_b_IN4, HIGH);
}

void set_motor_backward(void) {
  digitalWrite(pin_motor_b_IN3, HIGH);
  digitalWrite(pin_motor_b_IN4, LOW);
}

void set_motor_turnleft(void) {
  digitalWrite(pin_motor_a_IN1, HIGH);
  digitalWrite(pin_motor_a_IN2, LOW);
  delay(10);
  digitalWrite(pin_motor_a_IN1, LOW);
  digitalWrite(pin_motor_a_IN2, LOW);
  delay(25);
}

void set_motor_turnright(void) {
  Serial.println("Turn Right");
  digitalWrite(pin_motor_a_IN1, LOW);
  digitalWrite(pin_motor_a_IN2, HIGH);
  delay(10   );
  digitalWrite(pin_motor_a_IN1, LOW);
  digitalWrite(pin_motor_a_IN2, LOW);
  delay(25);
}

void set_motor_stop(void) {
  digitalWrite(pin_motor_b_IN3, LOW);
  digitalWrite(pin_motor_b_IN4, LOW);
}

void set_motor_stop_direciton(void) {
  digitalWrite(pin_motor_a_IN1, LOW);
  digitalWrite(pin_motor_a_IN2, LOW);
}

void error(int errno, char errchar) {
  switch (errno) {
    case 408:
      Serial.print(errchar);
      Serial.println(" : Can\'t undedstand BlueTooth communication");
      break;
    default:
      break;
  }
}