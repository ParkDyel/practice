#Linux(apt 계열) 개발 환경 구축

1. 시스템 구축 : 시스템 튜닝
 if RPi
  if raspibian
   sudo raspi-config && expand fileSystem
  else if linux for RPi
   expand fileSystem
  else linux
   ?
  sudo rpi-update
  sudo vim /boot/config
   arm_freq=1400
   arm_freq_min=1000
   over_voltage=6
   sdram_freq=500

 sudo apt-get update && sudo apt-get dist-upgrade -y
 sudo apt-get install -y ibus ibus-hangul
2. Console Program 설치 : VIM, fishshell, guake terminal, node.js, git
 curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
 sudo apt-get install -y vim guake fish nodejs git
 sudo npm install -g npm
 chsh -s `which fish`
 // guake setting
 {
  Toggle : Ctrl^`,
  NewTab : Ctrl^t,
  CloseTab : Ctrl^x,
  CopyToClip : Ctrl^Shift^c,
  PasteFromClip : Ctrl^shift^v,
  GoToPreTap : Ctrl^q,
  GoToNextTap : Ctrl^r,
  GoToLeftTap : Ctrl^w,
  GoToRightTap : Ctrl^e,
  GoTo{num}Tap : Ctrl^{num},
  ZoomIn : Ctrl^{RightArrow},
  ZoomOut : Ctrl^{LeftArrow},
  IncreseHegiht : Ctrl^{UpperArrow},
  DecreseHegiht : Ctrl^{LowerArrow}
}
3. IDE 설치 : Code, Atom, chromium
 // install chromium
 wget -qO - http://bintray.com/user/downloadSubjectPublicKey?username=bintray | sudo apt-key add -
 echo "deb http://dl.bintray.com/kusti8/chromium-rpi jessie main" | sudo tee -a /etc/apt/sources.list
 sudo apt-get update
 sudo apt-get install chromium-browser
 // install code
 sudo apt-get install libx11-dev
 git clone https://github.com/microsoft/vscode
 cd vscode
 ./scripts/npm.sh install --arch=armhf
4. 
