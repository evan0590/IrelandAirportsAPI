TARGET = model
TEMPLATE = lib
CONFIG += shared c++14 x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/arrivalsobject.h
HEADERS += arrivals.h
SOURCES += arrivals.cpp
HEADERS += sqlobjects/departuresobject.h
HEADERS += departures.h
SOURCES += departures.cpp
