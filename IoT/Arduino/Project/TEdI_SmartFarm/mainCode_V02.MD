# Arduino Smart Farm

## Description

## Circuit

## Code
```
// 라이브러리 추가
#include "DHT.h"

// define DHTTYPE 
#define DHTTYPE DHT22

// Pin 선언부
const int pin_dht22   = 2;
const int pin_soil    = A0;
const int pin_ldr     = A1;
const int pin_co2     = A2;
//const int 
const int pin_pump    = 10;
const int pin_fan     = 11;
const int pin_led     = 12;

// 변수 선언부
float val_temp  = 0;
float val_humi  = 0;
int val_soil    = 0;
float val_ldr   = 0;
int val_co2     = 0;

int threshold_soil  = 600;
int threshold_temp  = 30;
int threshold_humi  = 60;
int threshold_ldr   = 300;
int threshold_co2   = 500;

// 함수 선언부
int get_sensorValue(void);
float get_temp(int pinNum);
float get_humi(int pinNum);
int get_soil(int pinNum);
int get_LDR(int pinNum);
int get_co2(int pinNum);

void print_values(void);

void set_actuator(void);
void set_pumpMotor(int pinNum);
void set_fanMotor(int pinNum);
void set_Led(int pinNum);

// 객체 선언부

void setup(){
  pinMode(pin_soil, INPUT);
  pinMode(pin_ldr, INPUT);
  pinMode(pin_co2, INPUT);

  pinMode(pin_led, OUTPUT);
  pinMode(pin_pump, OUTPUT);
  pinMode(pin_fan, OUTPUT);

  Serial.begin(9600);
  dht.begin();
}

void loop(){
  get_sensorValue();
  print_values();
  set_actuator();
}

int get_sensorValue(void){
  val_temp = get_temp(pin_dht22);
  val_humi = get_humi(pin_dht22);
  val_soil = get_soil(pin_soil);
  val_ldr = get_LDR(pin_ldr);
  val_co2 = get_co2(pin_co2);
}

float get_temp(int pinNum){
  return dht.readTemperature();
}
float get_humi(int pinNum){
  return dht.readHumidity();
}
int get_soil(int pinNum){
  return analogRead(pinNum);
}
int get_LDR(int pinNum){
  return analogRead(pinNum);
}

int get_co2(int pinNum){
  return analogRead(pinNum);
}

void print_values(void){
  Serial.println(val_temp);
  Serial.println(val_humi);
  Serial.println(val_soil);
  Serial.println(val_ldr);
  Serial.println(val_co2);
}

void set_actuator(void){
  set_pumpMotor(pin_pump);
  set_fanMotor(pin_fan);
  set_Led(pin_led);
}

void set_pumpMotor(int pinNum){
  if(val_soil > threshold_soil){
    digitalWrite(pin_pump, HIGH);
    delay(10);
  } else {
    digitalWrite(pin_pump, LOW);
    delay(10);
  }
}
void set_fanMotor(int pinNum){
  if(val_temp > threshold_temp || val_humi > threshold_humi || val_co2 > threshold_co2){
    digitalWrite(pin_fan, HIGH);
    delay(10);
  } else {
    digitalWrite(pin_fan, LOW);
    delay(10);
  }  
}
void set_Led(int pinNum){
  if(val_ldr > threshold_ldr){
    digitalWrite(pin_led, HIGH);
    delay(10);
  } else {
    digitalWrite(pin_led, LOW);
    delay(10);
  }
}