#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T14:34:34
#
#-------------------------------------------------

QT       -= gui

TARGET = pcp_tactic
TEMPLATE = lib

DEFINES += PCP_TACTIC_LIBRARY

SOURCES += pcp_tactic.cpp

HEADERS += pcp_tactic.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
