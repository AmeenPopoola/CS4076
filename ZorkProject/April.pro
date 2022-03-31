QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console c++11

SOURCES += \
        Artifact.cpp \
        Character.cpp \
        Command.cpp \
        CommandWords.cpp \
        Parser.cpp \
        Room.cpp \
        ZorkUL.cpp \
        enemy.cpp \
        item.cpp \
        main.cpp \
        mainwindow.cpp \
        mummy.cpp

HEADERS += \
    Artifact.h \
    Character.h \
    Command.h \
    CommandWords.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    enemy.h \
    item.h \
    mainwindow.h \
    mummy.h



FORMS += \
    mainwindow.ui
