
QT       -= gui

TARGET = fillpolicy
TEMPLATE = lib

DEFINES += FILLPOLICY_LIBRARY

SOURCES += fillpolicy.cpp \
    ../../gpp_qt/wfunction/qtfunction.cpp

HEADERS += fillpolicy.h\
    ../../gpp_qt/wfunction/qtfunction.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-test_simu_dlls_step-Desktop_Qt_5_3_MSVC2013_32bit-Release/orderbook/release/ -lorderbook
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-test_simu_dlls_step-Desktop_Qt_5_3_MSVC2013_32bit-Release/orderbook/debug/ -lorderbook

INCLUDEPATH += $$PWD/../../build-test_simu_dlls_step-Desktop_Qt_5_3_MSVC2013_32bit-Release/orderbook/release
DEPENDPATH += $$PWD/../../build-test_simu_dlls_step-Desktop_Qt_5_3_MSVC2013_32bit-Release/orderbook/release
