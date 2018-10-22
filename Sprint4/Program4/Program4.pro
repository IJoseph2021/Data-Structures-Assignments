TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tester.cpp

HEADERS += \
    doublelinkedlist.h \
    node.h \
    catch.hpp \
    stack.h \
    adjacencylist.h
