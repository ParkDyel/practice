# ComplementaryFilter.md

## 개념

상보필터(Complementary Filter)는 각 센서에서 얻는 개별 신호보다 다른 주파수 특성의 센서 신호를 융합하여 보다 양호한 신호를 얻는 것이 기본개념이다.

이는 가속도와 자이로 센서를 이용하여 각을 계산할 때 사용되는 개념으로 같은 목적으로 사용되는 칼만 필터보다는 가벼운 알고리즘으로 단순한 IoT(사람)에 적용하기 쉽다. 

가속도 센서는 저주파 영역에서 평탄하고, 자이로 센서는 고주파 영역에서 평탄하다.

자이로 센서는 순간 정확하나 오차가 누적되고 가속도 센서는 민감하게 반응하나 순간 노이즈가 심하게 나타날 수 있어 이 두가지를 이용하여 보다 양호한 신호를 취득하는 것이다.

이외의 방법에도 위에 언급한 칼만 필터, DMP 등의 방법을 이용하여 보다 양호한 신호를 얻어낼 수 있다.

다만 이 두 센서에 대한 가중치는 같은 모델일지라도 여러 내/외 환경에 따라 다를 수 있으므로 실험 데이터를 통해 보정해나가야 하는 값으로 두 이득 곡선이 교차될 때의 값을 기준으로 수행하는 것이 가장 이상적이다. (1차 필터를 통한 측정 -> 2차 필터에 적용)

![fillter](http://cfile22.uf.tistory.com/image/207EAE1E4C475D7827E1AA)

## 공식

  alpha = 보정치

	angle = alpha * gyro_angle + (1.0 - alpha) * accel_angle
  #Accelerometer doesn't give z-angle 
	angle_z = gyro_angle_z; 

#### 참고 사이트

[개념](http://pinkwink.kr/349) http://pinkwink.kr/349 [PinkWink]
[공식](http://alnova2.tistory.com/1085) http://alnova2.tistory.com/1085

#### 관련 사이트

http://daddynkidsmakers.blogspot.kr/2015/09/complementary-filter-imu.html

http://sensibilityit.tistory.com/439

http://hyongdoc.tistory.com/47

http://alnova2.tistory.com/1085

http://blog.naver.com/PostView.nhn?blogId=roboholic84&logNo=220401407348

http://makeshare.org/bbs/board.php?bo_table=question&wr_id=1172


#### 경로
./IoT/MPU6050/withRPi.md

