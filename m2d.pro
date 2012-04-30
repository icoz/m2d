#-------------------------------------------------
#
# Project created by QtCreator 2012-04-26T12:21:15
#
#-------------------------------------------------

QT       += core gui

TARGET = m2d
TEMPLATE = app
MOC_DIR = build
UI_DIR = build
OBJECTS_DIR = build
RCC_DIR = build

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/block.cpp \
    src/mapscene.cpp \
    src/chunk.cpp \
    src/chunkmap.cpp

HEADERS  += src/mainwindow.h \
    src/block.h \
    src/block_types.h \
    src/mapscene.h \
    src/chunk.h \
    src/chunkmap.h

FORMS    += src/mainwindow.ui

OTHER_FILES += \
    spec.txt

RESOURCES += \
    res/res.qrc
