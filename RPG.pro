TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += headers\
        src

SOURCES += \
        main.cpp \
        src/controls.cpp \
        src/interactions.cpp \
        src/mapfunctions.cpp \
        src/menufunctions.cpp

HEADERS += \
    headers/characters.h \
    headers/controls.h \
    headers/interactions.h \
    headers/mapfunctions.h \
    headers/mappack.h \
    headers/menufunctions.h
