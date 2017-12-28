## configuration bluetooth module HC-06 on AT Mode



1. upload arduino code
   #include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
   int btTx=2;   //Tx (보내는핀 설정)at
   int btRx=3;   //Rx (받는핀 설정)
   SoftwareSerial btSerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
 
   void setup() 
   {
    Serial.begin(9600);   //시리얼모니터
    mySerial.begin(9600); //블루투스 시리얼
   }
   void loop()
   {
    if (mySerial.available()) {       
     Serial.write(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력
    }
    if (Serial.available()) {         
     mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
    }
   }

2. connect HC-06 and Arduino 
follow code

3. open Serial console

4. insert 'AT' on Serial console. and it will return 'OK'

5. If you want to chage BT device name, insert 'AT+NAME{wanted}' on console. it will return 'OKsetname'

6. If you want to chage BT device PIN number, insert 'AT+PIN{wanted}' on console. it will return 'OKsetPIN'

7. If you want to chage BT device baud rate, insert 'AT+BAUD{option}' on console. it will return 'OK{targetBps}'
###### Option list
+ 1----1200bps
+ 2----2400bps
+ 3----4800bps
+ 4----9600bps
+ 5----19200bps
+ 6----38400bps
+ 7----57600bps
+ 8----115200bps
+ 9----230400bps
+ A----460800bps
+ B----921600bps
+ C----1382400bps

8. addtional
AT+Pn where n is N (no parity), O (odd parity) or E (even parity). Firmware version higher than Linvor 1.5 only.
AT+VERSION responds with the firmware version.

9. factory Reset
Connect PIN 11 on BT Module board to LOW. but, i can't sure about that.
