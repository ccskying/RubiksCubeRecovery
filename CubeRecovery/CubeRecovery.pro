#-------------------------------------------------
#
# Project created by QtCreator 2018-06-05T15:27:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CubeRecovery
TEMPLATE = app


SOURCES += mainwindow.cpp \
    ccubetablewig.cpp \
    ccubecontrol.c \
    cubedata.c \
    main.cpp

HEADERS  += mainwindow.h \
    ccubetablewig.h \
    ccubecontrol.h \
    cubedata.h \
    arrayoperate.h \
    cubeoperations.h

FORMS    += mainwindow.ui
