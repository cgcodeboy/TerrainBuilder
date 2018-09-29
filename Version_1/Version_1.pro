#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T09:30:05
#
#-------------------------------------------------

QT       += core gui qml quick xml

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
    src\conbiner.cpp \
    src\simplecombiner.cpp \
    src\constraintconbiner.cpp \
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
    src\customergenerator.cpp \
    src\nature.cpp \
    src\water.cpp \
    src\thermal.cpp \

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
    include\conbiner.h \
    include\simplecombiner.h \
    include\constraintconbiner.h \
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
    include\customergenerator.h \
    include\nature.h \
    include\water.h \
    include\thermal.h

FORMS    += ui\mainwindow.ui \
    ui\perlinwidget.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    resource/item.xml
