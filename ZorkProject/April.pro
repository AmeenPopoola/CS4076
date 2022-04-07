QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console c++11

SOURCES += \
        Artifact.cpp \
        Character.cpp \
        Room.cpp \
        ZorkUL.cpp \
        enemy.cpp \
        image.cpp \
        item.cpp \
        main.cpp \
        mainwindow.cpp \
        mummy.cpp \
        wordle.cpp

HEADERS += \
    Artifact.h \
    Character.h \
    Room.h \
    ZorkUL.h \
    enemy.h \
    image.h \
    item.h \
    mainwindow.h \
    mummy.h \
    wordle.h



FORMS += \
    mainwindow.ui
