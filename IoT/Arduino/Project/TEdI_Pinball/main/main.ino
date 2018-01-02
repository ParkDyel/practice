#include "string.h"
#include <MsTimer2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define MAX_TIME 15

/* TimerCnt */
int Timer = MAX_TIME;

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // I2C LCD 객체 선언
Servo servo;

void ISR_Timer()
{
  Timer--;
  Serial.println(Timer);
}


void setup()
{
  MsTimer2::set(1000, ISR_Timer);     //1ms, ISR_Timer
  MsTimer2::start();
  Serial.begin(9600);    //Serial Baudrate Set

  lcd.begin(); // lcd를 사용을 시작합니다.
  lcd.backlight(); // backlight를 On 시킵니다.
  lcd.print("time"); // 화면에 Hello, world!를 출력합니다.

  servo.attach(9);
}

void loop()     //system loop
{
  int val_pot = analogRead(A0);
  int angle = map(val_pot, 0, 1023, 10, 170);
  servo.write(angle);

  lcd.setCursor(0, 1);
  lcd.print(Timer);
  lcd.print("               ");
  while(Timer<0){
    
  }
}