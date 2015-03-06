#-------------------------------------------------
#
# Project created by QtCreator 2015-02-16T09:06:27
#
#-------------------------------------------------

QT       -= gui

TARGET = optionf
TEMPLATE = lib

DEFINES += OPTIONF_LIBRARY

SOURCES += optionf.cpp

HEADERS += optionf.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
