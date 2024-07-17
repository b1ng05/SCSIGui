TEMPLATE = app
CONFIG += c++11
QT += widgets

SOURCES += src/main.cpp \
           src/mainwindow.cpp

HEADERS += include/mainwindow.h

FORMS += ui/mainwindow.ui

# Add build directory for generated files
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build

# Include directory for headers
INCLUDEPATH += include

