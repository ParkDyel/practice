# 리눅스 시스템 시작시에 자동 실행할 파일 등록하기

여러가지 방법이 있으나, 각기 알맞는 방법을 사용하는 것이 가장 좋다.
 
1. # vi /etc/rc.local 에서 바로 실행하기
- 해당 파일 하단에 실행 명령을 바로 넣어준다.
- 가능하면 실행 명령의 풀패스를 모두 적어주는 것이 좋다.
- 시스템(H/W)와 관련된 명령을 입력할 경우에는 부팅시 rc.local의 실행 순서가 빠르기 때문에 실행되지 않는 경우가 있을 수 있다. (이 경우에는 해당 시스템을 먼저 띄우는 방법을 사용하도록 한다.)
 
2. # vi /etc/rc.local 에 스크립트 파일을 등록하고, /etc/rc.d/ 경로에 해당 스크립트 파일 넣고 실행하기
- rc.local에서는 스크립트 파일을 불러오기만 하는 방법
- 작성할 스크립트 파일은 실행할 쉘을 먼저 지정해야 한다.
- 시스템(H/W)와 관련된 명령을 입력할 경우에는 부팅시 rc.local의 실행 순서가 빠르기 때문에 실행되지 않는 경우가 있을 수 있다. (이 경우에는 해당 시스템을 먼저 띄우는 방법을 사용하도록 한다.)
 
3. /etc/profile.d/ 경로에 자동실행할 스크립트 파일을 넣어 둔다.
- 위 경로에 있는 스크립트 파일들은 부팅시에 자동실행되는 파일들이다.
- 보통의 프로그램들을 가동하는데 많이 사용한다.
 
4. /usr/share/autostart/ 경로에 자동실행할 프로그램 파일을 생성한다.
- 위 경로에 있는 *.desktop 파일들은 부팅시에 자동실행되는 파일들이다.
- 기존에 있는 파일들과 같은 형식으로 원하는 파일을 만들어서 사용할 수 있다.
※ 만약 특정 계정에서만 위의 사항을 적용하고자 할때는,
    ~/kde/Autostart/ 경로에 설정한다.
 
 
[예제]
 
```
#===============================================================================
# vi /etc/rc.d/auto_start.sh
#===============================================================================
#!/bin/bash
# IEEE Mount
# /sbin/modprobe usbcore
# /sbin/modprobe usb-uhci
/sbin/modprobe ohci1394
/sbin/modprobe sbp2
/sbin/modprobe ieee1394
echo "scsi add-single-device 1 0 0 0" > /proc/scsi/scsi
echo "scsi add-single-device 1 0 1 0" > /proc/scsi/scsi
/bin/mount /dev/sdb1 /mnt/backup1
/bin/mount /dev/sdc1 /mnt/backup2
# Time Sync
/usr/bin/rdate -s time.nuri.net
 
```
```

#===============================================================================
# vi /etc/rc.local
#===============================================================================
#!/bin/sh
#
# This script will be executed *after* all the other init scripts.
# You can put your own initialization stuff in here if you don't
# want to do the full Sys V style init stuff.
touch /var/lock/subsys/local
sh /etc/rc.d/auto_start.sh

```
```
 
#===============================================================================
# vi /etc/profile.d/
#===============================================================================

```
