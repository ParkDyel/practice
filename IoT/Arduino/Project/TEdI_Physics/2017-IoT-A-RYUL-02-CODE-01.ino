/*
  Check Infra-Red Sensitive Photoregister
*/

const int readPin = A5;

int delayTime = 100;

void setup()
{
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.print(digitalRead(readPin));
  Serial.print(" : ");
  Serial.print(analogRead(readPin));
  Serial.println();
  delay(delayTime);
}