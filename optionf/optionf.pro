
QT       -= gui

TARGET = optionf
TEMPLATE = lib

DEFINES += OPTIONF_LIBRARY

SOURCES += optionf.cpp

HEADERS += optionf.h\
        optionf_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
