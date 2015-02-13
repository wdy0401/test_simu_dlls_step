#-------------------------------------------------
#
# Project created by QtCreator 2015-02-13T13:24:32
#
#-------------------------------------------------

QT       -= gui

TARGET = DG_tactic
TEMPLATE = lib

DEFINES += DG_TACTIC_LIBRARY

SOURCES += dg_tactic.cpp

HEADERS += dg_tactic.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
