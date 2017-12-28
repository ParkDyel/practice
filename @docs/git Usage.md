# Git Usage
2017.03.29
### init and push
#### Shell(2.12.2)
1. download [git](https://git-scm.com/downloads).
 - check to use in window's default console window. it's enough. use default check for the other option.

2. open the powershell.
3. create a new directory.

4. change work directory to the new directory.
5. make directory as git repo.
```
$ echo "# test" >> README.md // just make a README.md
$ git init
```

6. add files that will be add on repo.
```
$ git add README.md
```

7. config userEmail and userName on shell.
```
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```

8. commit and editing message for this.
```
$ git commit -m "first commit"
```

9. add git remote.
```
$ git remote add origin https://github.com/{UserName}/{repo.git}
```

10. push to git remote 'origin' as brunch 'master'
```
$ git push -u origin master
```
or just run at once 9,10
```
$ git push -u {repo.git} {brunchName}
```

11. login in Git as pop-up browser.

12. after this step, want to add files and commit, see it.
```
$ git add * or git add {file} {file} {file}
$ git commit -m {message}
$ git push -u {remotePath}/{remoteName} {brunchName}
```

#### Third party tool
##### GitKraken 