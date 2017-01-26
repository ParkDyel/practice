# 기본 폴더명 변경하기
###### http://kuroikuma.tistory.com/90

```
sudo vim /home/{user}/.config/user-dirs.dirs
```

```
//위치에 폴더가 존재해야 하는 것으로 여겨진다.
XDG_DESKTOP_DIR="$HOME/{DESKTOP_DIR_NAME}"
...
```

```
export LANG=C
xdg-user-dirs-gtk-update
```
