#-------------------------------------------------
#
# Project created by QtCreator 2010-04-23T16:59:39
#
#-------------------------------------------------

QT       += core gui

TARGET = Ned
TEMPLATE = app

SOURCES += src/main.cpp \
        src/MainWindow.cpp \
        src/FindDialog.cpp \
    src/QuickDialog.cpp

HEADERS  += src/MainWindow.h \
            src/FindDialog.h \
    src/QuickDialog.h

TRANSLATIONS += translations/ned_hu.ts

RESOURCES += \
    ned.qrc
