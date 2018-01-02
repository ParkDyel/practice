/*
* 청소로봇
* ParkDyel
* 2017.12.07
*/

#define pin_ultraSonic_trig 2
#define pin_ultraSonic_echo 3

#define pin_driver_dc_a_IN1 5
#define pin_driver_dc_a_IN2 6

#define pin_driver_dc_b_IN3 9
#define pin_driver_dc_b_IN4 10

#define pin_driver_dc_c_IN1 11
#define pin_driver_dc_c_IN2 12

#define val_speed 64
#define val_threshold_distance 5
#define val_time_drive_motor 200

void setup(){
  pinMode(pin_ultraSonic_trig, OUTPUT);
  pinMode(pin_ultraSonic_echo, INPUT);

  pinMode(pin_driver_dc_a_IN1, OUTPUT);
  pinMode(pin_driver_dc_a_IN2, OUTPUT);

  pinMode(pin_driver_dc_b_IN3, OUTPUT);
  pinMode(pin_driver_dc_b_IN4, OUTPUT);

  pinMode(pin_driver_dc_c_IN1, OUTPUT);
  pinMode(pin_driver_dc_c_IN2, OUTPUT);

  Serial.begin(9600);
  Serial.println("Start Serial Communication");
  set_motor_cleanner();
}

void loop(){
  int distance = get_distance(pin_ultraSonic_trig, pin_ultraSonic_echo);
  set_Motor(distance);
}

int get_distance(int trigPin, int echoPin) {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  return distance;
}

void set_Motor(int distance) {
  if (distance > val_threshold_distance) {
    set_motor_forward(val_time_drive_motor);
  } else {
    set_motor_backword(val_time_drive_motor);
    delay(val_time_drive_motor*10);
    set_motor_turnleft(val_time_drive_motor);
  }
}

void set_motor_forward(int delay_time) {
  digitalWrite(pin_driver_dc_a_IN1, val_speed);
  digitalWrite(pin_driver_dc_a_IN2, LOW);
  digitalWrite(pin_driver_dc_b_IN3, val_speed);
  digitalWrite(pin_driver_dc_b_IN4, LOW);
  delay(delay_time);
}

void set_motor_turnleft(int delay_time) {
  digitalWrite(pin_driver_dc_a_IN1, LOW);
  digitalWrite(pin_driver_dc_a_IN2, LOW);
  digitalWrite(pin_driver_dc_b_IN3, val_speed);
  digitalWrite(pin_driver_dc_b_IN4, LOW);
  delay(delay_time*2);
}

void set_motor_backword(int delay_time){
  digitalWrite(pin_driver_dc_a_IN1, LOW);
  digitalWrite(pin_driver_dc_a_IN2, val_speed);
  digitalWrite(pin_driver_dc_b_IN3, LOW);
  digitalWrite(pin_driver_dc_b_IN4, val_speed);
  delay(delay_time);
}

void set_motor_cleanner(void){
  digitalWrite(pin_driver_dc_c_IN1, val_speed);
  digitalWrite(pin_driver_dc_c_IN2, LOW);
}