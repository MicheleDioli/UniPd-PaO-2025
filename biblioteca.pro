######################################################################
# Automatically generated by qmake (3.1) Fri Feb 7 11:28:20 2025
######################################################################

TEMPLATE = app
TARGET = biblioteca
INCLUDEPATH += .
QT += widgets
# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x060000 # disables all APIs deprecated in Qt 6.0.0 and earlier

# Input
HEADERS += src/Articolo.h \
           src/ConstVisitorInterface.h \
           src/Film.h \
           src/Libro.h \
           src/Rivista.h \
           src/VisitorInterface.h \
           src/view/Crea/Nuovo.h \
           src/view/Json/Json.h \
           src/view/Json/JsonImporter.h \
           src/view/Json/JsonVisitor.h \
           src/view/Modifica/editVisitor.h \
           src/view/Modifica/ModificaArticolo.h \
           src/view/Modifica/ModificaFilm.h \
           src/view/Modifica/ModificaLibro.h \
           src/view/Modifica/ModificaRivista.h \
           src/view/Sensoriqt/Cliccabile.h \
           src/view/Sensoriqt/FiltroLayout.h \
           src/view/Sensoriqt/ListaArticoli.h \
           src/view/Sensoriqt/ListaQT.h \
           src/view/Sensoriqt/ListaVisitor.h
SOURCES += main.cpp \
           src/Articolo.cpp \
           src/Film.cpp \
           src/Libro.cpp \
           src/Rivista.cpp \
           src/view/Crea/Nuovo.cpp \
           src/view/Json/Json.cpp \
           src/view/Json/JsonImporter.cpp \
           src/view/Json/JsonVisitor.cpp \
           src/view/Modifica/editVisitor.cpp \
           src/view/Modifica/ModificaArticolo.cpp \
           src/view/Modifica/ModificaFilm.cpp \
           src/view/Modifica/ModificaLibro.cpp \
           src/view/Modifica/ModificaRivista.cpp \
           src/view/Sensoriqt/Cliccabile.cpp \
           src/view/Sensoriqt/FiltroLayout.cpp \
           src/view/Sensoriqt/ListaArticoli.cpp \
           src/view/Sensoriqt/ListaQT.cpp \
           src/view/Sensoriqt/ListaVisitor.cpp
RESOURCES += src/resources.qrc
