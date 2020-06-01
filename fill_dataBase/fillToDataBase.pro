TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += sql

SOURCES += \
        fillToDataBase.cpp \
        main.cpp

HEADERS += \
    fillToDataBase.h
