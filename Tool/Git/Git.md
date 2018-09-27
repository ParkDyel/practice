# Git Usage

2018.09.27

## Git이란

프로젝트 코드를 추적하기 쉽게 해주는 버전(이력) 관리 시스템이다. 코드의 변경 사항을 쉽게 추적할 수 있으며 상태를 제어할 수 있다. 또한 여러 사람이 동시에 작업할 수 있도록 복사본을 관리할 수 있는 시스템이다. 예를 들어 하나의 프로젝트에 세명의 개발자가 동시에 버그를 고칠 때 하나의 원본에서 각자의 복사본을 생성하고 문제를 수정 한 후 다시 원본에 병합하는 과정을 지원한다. 물론 이 과정에서 충돌이 발생할 수 있다.

## Git Hub란

GitHub란 Git을 Network 상에 공유하여 여러 사람이 작업을 공유할 수 있도록 하고 나아가 코드를 공개함으로 더 많은 사람들이 코드를 공유하여 함께 문제점을 찾고 프로젝트에 기여할 수 있도록 하는 서비스이다. 꼭 public으로 공개되어있지 않고 제한된 인원에게만 공유되는 private 서비스도 있다.

[github](https://github.com/)
[gitbucket](https://bitbucket.org/)

## easy start

1. download [git](https://git-scm.com/downloads).
    - check to use in window's default console window. it's enough. use default check for the other option.
2. open the powershell.
3. create a new directory.
4. change 'work directory' to the new directory.
5. make directory as git repo.
    ```bash
    git init
    ```
6. create the REDEME.md.
    ```bash
    echo '#README.md' >> README.md
    ```
7. add files that will be add on repo.
    ```bash
    git add README.md
    ```
8. config userEmail and userName on shell.
    ```bash
    git config --global user.email "you@example.com"
    git config --global user.name "Your Name"
    ```
9. commit and edit commit message
    ```bash
    git commit -m "first commit"
    ```
10. add git remote.
    ```bash
    git remote add origin https://github.com/{UserName}/{repo.git}
    ```
11. push to git remote 'origin' as brunch 'master'
    ```bash
    git push -u origin master
    ```
    or just run at once 9,10
    ```bash
    git push -u {repo.git} {brunchName}
    ```

## Case

1. 다른 작업 환경을 구성하기 위해 새로운 branch를 생성
    1. 현재 branch 확인
        ```bash
        git checkout
        ```
    2. local에서 추적중인 branch 확인
        ```bash
        git branch -r
        ```
    3. git hub의 branch 목록 갱신
        ```bash
        git fetch
        ```
    4. branch 생성
        ```bash
        git branch `${NewBranch}`
        ```
    5. branch 전환
        ```bash
        git checkout `${NewBranch}`
        ```
    ps) 4번 항목과 5번 항목을 다음 명령어로 한번에 실행할 수 있다.
        ```bash
        git checkout -b `${NewBranch}`
        ```
1. 변경 사항 확인
    1. 변경된 코드 확인
        ```bash
        git diff
        ```
    2. 변경된 이력 확인
        ```bash
        git log
        ```
        
1. Git 설치 시 설정한 설정 변경
    1. global   
        ```bash
        git config --global --edit
        ```
