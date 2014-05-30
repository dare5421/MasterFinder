#-------------------------------------------------
#
# Project created by QtCreator 2014-05-26T21:02:11
#
#-------------------------------------------------

QT       += core gui
QT           += sql widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MasterFinder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    connection.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
