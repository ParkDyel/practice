# Arduino Smart Farm

## Description

## Circuit

## Code
```
// 라이브러리 추가

// Pin 선언부
const int 

// 변수 선언부
int flag_motor=0;
int flag_fan=0;


// Involt received Data.
int    involtPin[14] = {}; //equals involt.pin.P in app
String involtString[2] ={}; //equals involt.pin.S in app

char involt[16];

// 함수 선언부
int get_sensorValue(void);
float get_temp(int pinNum);
float get_humi(int pinNum);
float get_soil(int pinNum);
float get_CO2(int pinNum);
float get_LDR(int pinNum);

void set_actuator(void);
void set_motor(int pinNum);
void set_fan(int pinNum);

// 객체 선언부

void setup(){

}

void loop(){
  involtReceive();


  get_sensorValue();
  set_actuator();
  fname = "";
}


