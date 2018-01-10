# withRPi.md

   RaspberryPi에서 MPU6050을 사용하기 위한 절차 설명


1. RPi I2C 통신 활성화

```
$ sudo raspi-config
```

위 명령어를 쉘(CLI)에 명령하면 RaspberryPi 설정환경이 실행되는데 interface(구 버전에선 advanced) 옵션에서 I2C를 활성화(enable)한다.


2. RPi I2C 통신 주소 확인

```
$ sudo apt-get install i2c-tools
$ sudo apt-get install python-smbus 
```

근래의 Raspbian OS 에는 위 두 툴이 설치되어 있으나 확인차 위의 설치 명령어를 실행한다.

```
$ i2cdetect -y -r 1
```

RPi의 I2C interface에 연결된 장치들의 주소값을 출력한다. 매개변수에 대해서는 다음 명령어를 통해서 살펴볼 수 있다.
(일부 이전 모델에서는 i2cdetect -y -r 0을 사용해야 한다.)

```
$ man i2cdetect
```

3. python code

  python에 익숙한 분들은 다음 링크의 패키지를 받아서 사용을 하면 된다.

```
https://github.com/Tijndagamer/mpu6050/
```

  익숙하지 않은 분들은 다음 방법을 통해 단일 파일을 가져오도록 한다.

```
$ wget https://raw.githubusercontent.com/Tijndagamer/mpu6050/master/mpu6050/mpu6050.py
```

 위 명령을 실행하면 쉘의 현재 작업 디렉터리에 파일을 가져와 저장한다. 

line 244~254의 코드가 프로그램의 시작이자 끝이다.

_자세한 내용은 복잡하여 쉽게 설명하였다._
  
line 245의 0x68이 i2c 통신의 주소이고, line 246은 온도 센서 값을 측정하여 출력하고, line 247, 251의 코드가 값을 측정하도록 하는 함수를 실행하고 반환값을 상수에 대입하는 코드이다. 그 이외의 print문은 상수 값을 출력하는 코드이다.

#### 경로
./IoT/MPU6050/withRPi.md