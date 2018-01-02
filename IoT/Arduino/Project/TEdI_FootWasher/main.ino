/*
* 족욕기
* ParkDyel
* 2017.12.07
*/

#define pin_motor_a_IN1 5 // washer
#define pin_motor_a_IN2 6 // washer
#define pin_motor_b_IN3 9 // dry
#define pin_motor_b_IN4 10 // dry
#define pin_sw_tact_a 2
#define pin_sw_tact_b 3

#define time_delay_motor 100
#define time_delay_chattering 1000

int state=0;
int speed_motor=128;

void set_start(void);
void set_speed_motor(void);
void set_water_in(void);
int get_waterlevel(void);
void set_motor_all_stop(void);
void set_motor_washer(int speed);
void set_motor_dry(int speed);
void set_water_out(void);

void setup(){
  pinMode(pin_motor_a_IN1, OUTPUT);
  pinMode(pin_motor_a_IN2, OUTPUT);
  pinMode(pin_motor_b_IN3, OUTPUT);
  pinMode(pin_motor_b_IN4, OUTPUT);

  pinMode(pin_sw_tact_a, INPUT);
  pinMode(pin_sw_tact_b, INPUT);

  //chattering!
  attachInterrupt(digitalPinToInterrupt(pin_sw_tact_a), set_state, RISING);
  attachInterrupt(digitalPinToInterrupt(pin_sw_tact_b), set_speed_motor, RISING);

  Serial.begin(9600);
}

void loop(){
  if(state == 1){
    // start washer
    set_motor_washer(speed_motor);
    delay(time_delay_motor);
  } else if(state == 2){
    set_motor_washer(LOW);
    set_motor_dry(speed_motor);
    delay(time_delay_motor);
  } else {
    set_motor_all_stop();
  }
  Serial.println(state);
}

void set_state(void){
  state = !state;
}
void set_speed_motor(void){
  speed_motor = speed_motor + 64;
  if(speed_motor>255){
    speed_motor = speed_motor - 256;
  }
}

void set_water_in(void){
  //set water supply valve open
}

int get_waterlevel(void){
  
}

void set_motor_all_stop(){
  digitalWrite(pin_motor_a_IN1, LOW);
  digitalWrite(pin_motor_a_IN2, LOW);  
  digitalWrite(pin_motor_b_IN3, LOW);  
  digitalWrite(pin_motor_b_IN4, LOW);
  Serial.println("Motor All Stop");
}

void set_motor_washer(int value_motor_speed){
  analogWrite(pin_motor_a_IN1, value_motor_speed);
  analogWrite(pin_motor_a_IN2, LOW);
  Serial.println("Motor Washer Set");
}

void set_motor_dry(int value_motor_speed){
  analogWrite(pin_motor_b_IN3, value_motor_speed);
  analogWrite(pin_motor_b_IN4, LOW);
  Serial.println("Motor Dry Set");
}

void set_water_out(void){
  //set drainage system valve open
}