TARGET = testarrivals
TEMPLATE = app
CONFIG += console debug c++14
CONFIG -= app_bundle
QT += network sql testlib
QT -= gui
DEFINES += TF_DLL
INCLUDEPATH += ../..
LIBS += -L../../lib -lmodel
include(../../appbase.pri)
SOURCES = testarrivals.cpp      # Specifying the file name