#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T09:30:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TerrainBuilder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainview.cpp \
    item.cpp \
    generator.cpp \
    layoutgenerator.cpp \
    constantgenerator.cpp \
    perlingenerator.cpp \
    gradientgenerator.cpp \
    itemfactory.cpp

HEADERS  += mainwindow.h \
    mainview.h \
    item.h \
    generator.h \
    layoutgenerator.h \
    constantgenerator.h \
    perlingenerator.h \
    gradientgenerator.h \
    itemfactory.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
