# Install Docker On Windows

1. Docker CE 설치 
    - [사이트](https://store.docker.com/editions/community/docker-ce-desktop-windows)
2. Kitematic 설치
    1. Docker가 성공적으로 설치된 후 실행하여 트레이 아이콘에서 마우스 오른쪽 버튼을 클릭하여 kitematic을 누른다.
    2. 압축파일을 다운로드 한 다음 %program files%docker에 압축을 푼다.
    * 설치 후 정상적으로 kitematic이 실행되지 않으면 %AppData%Roaming/Kitematic/Local Storage를 삭제한다.

3. docker 이미지 설치
    1. 기껏 열심히 kitematic을 설치했는데, 버전을 골라서 설치하는 방법을 몰라서 CLI를 이용했다.
    2. 
        ```
        $ docker pull tiangolo/uwsgi-nginx:python3.6
        ```
    3. kitematic에서 tag를 고르는 방법을 알아냈다. 다시 이미지를 지우자.
    4. docker images // 설치된 이미지를 확인한다.
    5. docker rmi {Image_ID} // 설치된 특정 이미지를 제거한다. 출력된 항목 중에 ID 값이 있다.

4. [mysql 설치](https://tecadmin.net/install-mysql-server-on-debian9-stretch/)
    * 그냥 설치하면 maria DB가 깔린다. 이게 왠걸.. 3번째 명령어줄은 작성자가 필요한 패키지를 설치하는 것이지만 이 중 sudo와 lsb-release는 설치를 위해 설치해야한다(사실 sudo는 명령어에서 빼기만 해도 무방해보인다. debian에 대한 확신이 없다)
    1)
        ```
        1| apt update 
        2| apt upgrade
        3| apt install vim sudo fish lsb-release
        ```
    2)
        ```
        1| wget http://repo.mysql.com/mysql-apt-config_0.8.9-1_all.deb
        2| sudo dpkg -i mysql-apt-config_0.8.9-1_all.deb
        ```
    - 2)2 과정에서 에러 메세지에 lsb-release를 설치하려고 하면 그대로 이행하도록 한다. 설치하면서 sudo도 필요하다면 같이 설치하도록 한다.
    3)
        ```
        1| sudo apt update 
        2| sudo apt install mysql-server python-mysqldb
        3| pip install mysql-python
        ```
    
