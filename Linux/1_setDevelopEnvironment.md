## DE : Ubuntu on VirtualBox

1. install OS on VirtualBox(Orcle)
    1. downloads [VirtualBox(oracle)]().
    2. downloads [Ubuntu Desktop]().
    3. install Ubuntu on VM.

2. install a basic dev-tool.
    - install vim, fish shell, guake terminal, git via cmd.
    ```
    sudo apt-get update && sudo apt-get upgrade -y
    sudo apt-get install -y vim guake fish git
    ```

3. install a basic tool
    - upgrade OS, and install Visual studio Code via Ubuntu Software Center.
    - install whale, gitKraken, via www

4. install the Node.js
    ```
    curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
    sudo apt-get install -y nodejs 
    sudo npm install -g npm
    ```

5. [set the python](https://stackoverflow.com/questions/15221473/how-do-i-update-pip-itself-from-inside-my-virtual-environment)
    - remove python2, and set python3 as python.

    _나중에 재설치할 일이 있으면 제거 하지말고 경로만 python3을 python으로 python를 python2로 변경해보자. python2를 지우고 재설치하니 python2이 되긴했다._

    ```
    sudo apt purge python2.7-minimal
    sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.5 1
    python --version
    python -m pip install -U pylint
    ```
    - install and upgrade pip.
    ```
    sudo apt install python-pip
    pip install --upgrade pip
    ```