#-------------------------------------------------
#
# Project created by QtCreator 2012-04-26T12:21:15
#
#-------------------------------------------------

QT       += core gui

TARGET = m2d
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/block.cpp

HEADERS  += src/mainwindow.h \
    src/block.h \
    src/block_types.h

FORMS    += src/mainwindow.ui

OTHER_FILES += \
    spec.txt

RESOURCES += \
    res/res.qrc
