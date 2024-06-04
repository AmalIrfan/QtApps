QtApps
======

Simple apps build using Qt.

Dependency:
```shell
$ sudo apt install qtbase5-dev
```

For creating a new project:
```shell
$ mkdir Calculator
$ cd Calculator
$ touch Calculator.cpp
$ qmake -project
$ qmake
$ make
$ ./Calculator
```

Also add these lines in `.pro` file:
```
INCLUDEPATH += .

QT += gui
QT += widgets
```

- [Calculator](Calculator/README.md)
