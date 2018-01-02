/*
* 대기측정봇! - E:atmosphere
* 
* 2017.12.07
*/

#include "LedControl.h"
#include "DHT.h"

// Temperature & Humidity Sensor, typeof DHT11
#define DHTPIN 7
#define DHTTYPE DHT11 // DHT 11

// UltraSonic Sensor
#define pin_trig 2
#define pin_echo 3
#define threshold_distance 10

// Left/Right Motor
#define pin_motor_a_IN1 5
#define pin_motor_a_IN2 6

// Left/Right Motor
#define pin_motor_b_IN1 8
#define pin_motor_b_IN2 9

#define time_delay 1000

// LED Matrix Module
#define pin_matrix_din 12
#define pin_matrix_clk 11
#define pin_matrix_CS 10

// Create object
DHT dht(DHTPIN, DHTTYPE);
LedControl lc = LedControl(12, 11, 10, 1);

// Emoticon Array
byte great[8] = {
  // 0x00, 0x22, 0x55, 0x00, 0x00, 0x22, 0x1c, 0x00
  0x00, 0x04, 0x12, 0x24, 0x20, 0x24, 0x12, 0x04
};

byte good[8] = {
  // 0x00, 0x22, 0x55, 0x00, 0x00, 0x3e, 0x00, 0x00
  0x00, 0x04, 0x22, 0x24, 0x20, 0x24, 0x22, 0x04
};

byte soSo[8] = {
  // 0x00, 0x00, 0x77, 0x00, 0x08, 0x36, 0x00, 0x00
  0x00, 0x04, 0x24, 0x24, 0x10, 0x24, 0x24, 0x04
};

byte bad[8] = {
  // 0x41, 0x63, 0x36, 0x00, 0x08, 0x14, 0x22, 0x00
  0x00, 0x06, 0x8c, 0x48, 0x20, 0x48, 0x8c, 0x06
};
byte error[8] = {
  B11000011,
  B01100110,
  B00111100,
  B00011000,
  B00111100,
  B01100110,
  B11000011
};

int get_distance(int trigPin, int echoPin);         // get distance from Ultra-sonic Sensor to recognize obstacles.
float get_disComfortIndex(float temp, float humi);  // get Discomport index to know state of atmosphere instinctively.
void set_matrix(byte emoticonArray[]);              // set dot Matrix Out.
void set_array(int dI);                             // set array that express emotion.
void set_Motor(int distance);                       // set Motor go straight or turn left. 
void set_motor_forward(int delay_time);             // set Motor to go straight.
void set_motor_turnleft(int delay_time);            // set Motor to go turn left.

void setup() {
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);

  pinMode(pin_motor_a_IN1, OUTPUT);
  pinMode(pin_motor_a_IN2, OUTPUT);
  pinMode(pin_motor_b_IN1, OUTPUT);
  pinMode(pin_motor_b_IN2, OUTPUT);

  // initalize LED DotMatrix
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  // initalize DHT
  dht.begin();

  Serial.begin (9600);
  Serial.println("Serial Communication!");
}

void loop() {
  int distance = get_distance(pin_trig, pin_echo);
  Serial.println(distance);
  set_Motor(distance);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    set_array(error);
    return;
  }

  int dI = get_disComfortIndex(t, h);
  set_array(dI);
}

int get_distance(int trigPin, int echoPin) {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  return distance;
}

void set_Motor(int distance) {
  if (distance > threshold_distance) {
    set_motor_forward(time_delay);
  } else {
    set_motor_turnleft(time_delay);
  }
}

void set_motor_forward(int delay_time) {
  digitalWrite(pin_motor_a_IN1, HIGH);
  digitalWrite(pin_motor_a_IN2, LOW);
  digitalWrite(pin_motor_b_IN1, HIGH);
  digitalWrite(pin_motor_b_IN2, LOW);
  delay(delay_time);
}

void set_motor_turnleft(int delay_time) {
  digitalWrite(pin_motor_a_IN1, LOW);
  digitalWrite(pin_motor_a_IN2, LOW);
  digitalWrite(pin_motor_b_IN1, HIGH);
  digitalWrite(pin_motor_b_IN2, LOW);
  delay(delay_time*2);
}

float get_disComfortIndex(float temp, float humi) {
  return (1.8f * temp) - (0.55 * (1 - humi / 100.0f) * (1.8f * temp - 26)) + 32;
}

void set_matrix(byte emoticonArray[]) {
  for (int i = 0; i < 7; i++)
    lc.setRow(0, i, emoticonArray[i]);
  delay(time_delay / 10);
}

void set_array(int dI) {
  switch (dI) {
    case 80 ... 100:
      set_matrix(bad);
      Serial.println(" : Bad");
      break;
    case  75 ... 79:
      set_matrix(soSo);
      Serial.println(" : soSO");
      break;
    case 68 ... 74:
      set_matrix(good);
      Serial.println(" : good");
      break;
    default:
      set_matrix(great);
      Serial.println(" : Great");
      break;
  }
}