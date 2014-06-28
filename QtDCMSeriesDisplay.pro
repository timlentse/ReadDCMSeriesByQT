#-------------------------------------------------
#
# Project created by QtCreator 2013-03-11T11:26:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtDCMSeriesDisplay
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
LIBS    += -LD:/vtk_qt1/bin/ -llibvtkCommon -llibvtksys -llibQVTK\
-llibvtkQtChart -llibvtkViews -llibvtkWidgets -llibvtkInfovis -llibvtkRendering\
-llibvtkGraphics -llibvtkImaging -llibvtkIO -llibvtkFiltering -llibvtklibxml2\
-llibvtkDICOMParser -llibvtkpng -llibvtkpng -llibvtktiff -llibvtkzlib -llibvtkjpeg\
-llibvtkalglib -llibvtkexpat -llibvtkverdict -llibvtkmetaio -llibvtkNetCDF\
-llibvtkexoIIc -llibvtkftgl -llibvtkfreetype -llibvtkHybrid -llibvtkVolumeRendering

INCLUDEPATH += D:/vtk_qt1/include/vtk-5.10

RESOURCES += \
    resource.qrc
