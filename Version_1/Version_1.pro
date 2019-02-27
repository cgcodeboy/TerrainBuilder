#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T09:30:05
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TerrainBuilder
TEMPLATE = app


SOURCES += src\main.cpp\
        src\mainwindow.cpp \
    src\mainview.cpp \
    src\item.cpp \
    src\generator.cpp \
    src\layoutgenerator.cpp \
    src\constantgenerator.cpp \
    src\perlingenerator.cpp \
    src\gradientgenerator.cpp \
    src\itemfactory.cpp \
    src\output.cpp \
    src\heightoutput.cpp \
    src\textureoutput.cpp \
    src\combiner.cpp \
    src\simplecombiner.cpp \
    src\constraintcombiner.cpp \
    src\filter.cpp \
    src\perlinwidget.cpp \
    src\iteminquirer.cpp \
    src\radialgenerator.cpp \
    src\voronoigenerator.cpp \
    src\terrace.cpp \
    src\clamp.cpp \
    src\noise.cpp \
    src\blur.cpp \
    src\math.cpp \
    src\add.cpp \
    src\subtract.cpp \
    src\multiply.cpp \
    src\divide.cpp \
    src\invert.cpp \
    src\sqrt.cpp\
    src\nature.cpp \
    src\water.cpp \
    src\thermal.cpp \
    src\perlin.cpp \
    src\itemcollector.cpp \
    src\bezierline.cpp \
    src\addwidget.cpp \
    src\constantwidget.cpp \
    src\itemdrawmaster.cpp \
    src\radialwidget.cpp \
    src\voronoiwidget.cpp \
    src\layoutwidget.cpp \
    src\paintwidget.cpp \
    src\gradientwidget.cpp \
    src\constraintwidget.cpp \
    src\subtractwidget.cpp

HEADERS  += include\mainwindow.h \
    include\mainview.h \
    include\item.h \
    include\generator.h \
    include\layoutgenerator.h \
    include\constantgenerator.h \
    include\perlingenerator.h \
    include\gradientgenerator.h \
    include\itemfactory.h \
    include\output.h \
    include\heightoutput.h \
    include\textureoutput.h \
    include\combiner.h \
    include\simplecombiner.h \
    include\constraintcombiner.h \
    include\filter.h \
    include\perlinwidget.h \
    include\iteminquirer.h \
    include\radialgenerator.h \
    include\voronoigenerator.h \
    include\terrace.h \
    include\clamp.h \
    include\noise.h \
    include\blur.h \
    include\math.h \
    include\add.h \
    include\subtract.h \
    include\multiply.h \
    include\divide.h \
    include\invert.h \
    include\sqrt.h\
    include\nature.h \
    include\water.h \
    include\thermal.h \
    include\perlin.h \
    include\itemcollector.h \
    include\bezierline.h \
    include\addwidget.h \
    include\constantwidget.h \
    include\itemdrawmaster.h \
    include\radialwidget.h \
    include\voronoiwidget.h \
    include\layoutwidget.h \
    include\paintwidget.h \
    include\shape.h \
    include\gradientwidget.h \
    include\constraintwidget.h \
    include\subtractwidget.h

FORMS    += ui\mainwindow.ui \
    ui\perlinwidget.ui \
    ui\addwidget.ui \
    ui\constantwidget.ui \
    ui\radialwidget.ui \
    ui\voronoiwidget.ui \
    ui\layoutwidget.ui \
    ui\gradientwidget.ui \
    ui\constraintwidget.ui \
    ui\subtractwidget.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    resource/item.xml

INCLUDEPATH += D:\CImg-2.2.2

LIBS += -lgdi32 -luser32
