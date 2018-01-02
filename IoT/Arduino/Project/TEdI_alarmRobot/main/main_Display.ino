/*
* 알람로봇! - 4-Digit-SevenSegment
* 
* 2017.12.07
*/
int position_pin[] = {13, 2, 3, 4};              // 세그멘트 자리 수 결정 핀
int segment_pin[] = {5, 6, 7, 8, 9, 10, 11, 12}; // 세그먼트 출력 제어 핀
const int delayTime = 5;                         // 인터벌 시간

// 각각의 0 ~ 9를 표현하는 세그먼트 값들
byte data[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};

void show(int position, int number);            // position 세그먼트에 한 자리 수 number를 출력합니다.
void count(void);                               // 4-SevenSegment에 4자리수 카운터를 출력한다.

void setup()
{
  //4자리 결정 핀 출력용으로 설정
  for (int i = 0; i < 4; i++)
  {
    pinMode(position_pin[i], OUTPUT);
  }

  //세그먼트 제어 핀 출력용으로 설정
  for (int i = 0; i < 8; i++)
  {
    pinMode(segment_pin[i], OUTPUT);
  }
}

void loop()
{
  show(1, 1); //첫 번째 자리, 1출력
  delay(delayTime);
  show(2, 2); //두 번째 자리, 2출력
  delay(delayTime);
  show(3, 3); //세 번째 자리, 3출력
  delay(delayTime);
  show(4, 4); //네 번째 자리, 4출력
  delay(delayTime);
}

void show(int position, int number)
{
  //4자리 중 원하는 자리 선택
  for (int i = 0; i < 4; i++)
  {
    if (i + 1 == position)
    {
      digitalWrite(position_pin[i], LOW);
    }
    else
    {
      digitalWrite(position_pin[i], HIGH);
    }
  }

  //8개 세그먼트를 제어해서 원하는 숫자 출력
  for (int i = 0; i < 8; i++)
  {
    byte segment = (data[number] & (0x01 << i)) >> i;
    if (segment == 1)
    {
      digitalWrite(segment_pin[7 - i], HIGH);
    }
    else
    {
      digitalWrite(segment_pin[7 - i], LOW);
    }
  }
}

/*
 0001부터 하나씩 카운트하는 함수
*/
void count(void)
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      for (int k = 0; k < 10; k++)
      {
        for (int l = 0; l < 10; l++)
        {
          show(1, i);
          delay(delayTime);
          show(2, j);
          delay(delayTime);
          show(3, k);
          delay(delayTime);
          show(4, l);
          delay(delayTime);
        }
      }
    }
  }
  delay(1000);
}