TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS +=$$PWD/luawrapper/*.hpp \
    testclass.h \
    luatestclass.h
SOURCES += main.cpp \
    testclass.cpp \
    luatestclass.cpp

include(deployment.pri)
qtcAddDeployment()


INCLUDEPATH += $$PWD/lua-5.3.3/src

INCLUDEPATH += $$PWD/luawrapper
LIBS += -L./lua-5.3.3/src -llua -ldl

DISTFILES += \
    testLua.lua
