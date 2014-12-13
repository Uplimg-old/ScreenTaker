QT += core gui widgets
TARGET = screenmanager
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    screenmanager.cpp \
    areauserdefiner.cpp

HEADERS += \
    screenmanager.h \
    areauserdefiner.h
