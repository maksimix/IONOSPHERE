<QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE	= app
CONFIG		+= qt warn_on thread release
#CONFIG		+= qt warn_on release

#LIBS            = ../f2c/vcf2c.lib
#LIBS            = ../f2c/libf2c.a
#gfortran
#LIBS            = ../iri_3d/iri2007/libiri2007.a -lgfortran
LIBS            = ../iri2012/libiri2012.a -lgfortran
#g77
#LIBS            = ../iri_3d/iri2007/libiri2007.a -lg2c
TARGET          = profil
DEPENDPATH=../../include 
#INTERFACE_DECL_PATH=.
DEFINES     = _POSIX GL
#DEFINES     = GL  
QMAKE_LFLAGS_WINDOWS = /NODEFAULTlIB:MSVCRT.LIB
QMAKE_CFLAGS_RELEASE = 
QMAKE_CXXFLAGS_RELEASE = 
QMAKE_CFLAGS_MT= 
QMAKE_CXXFLAGS_MT=
#LANGUAGE	= C++
TRANSLATIONS = ./profil_ru.ts
MOC_DIR = ./.moc
OBJECTS_DIR = ./.obj
UI_DIR = ./ui


HEADERS		= mainwindow.h \
                  ../iri_3d/iri_3d_new.h \
                  ../splayn/spcub.h \
                  ../draw_qt4/draw.h \
                  ../draw_qt4/drawbase.h \
                  ../draw_qt4/drawmem.h \
                  ../draw_qt4/drawmembase.h

SOURCES		= main.cpp \
                  mainwindow.cpp \
		  ../splayn/spcub.cpp \
                  ../splayn/progon.cpp \
#                  main__.c \
		  ../iri_3d/eschar.cpp \
                  ../iri_3d/iri_3d_new.cpp \
                  ../draw_qt4/drawmem.cpp \
                  ../draw_qt4/draw.cpp \
                  ../draw_qt4/grrazmem.cpp \
                  ../draw_qt4/grraz.cpp \
                  ../draw_qt4/drawmembase.cpp \
                  ../draw_qt4/drawbase.cpp
                  
		  
INTERFACES      = ./ui/profilwindow.ui \
                  ./ui/options.ui \
                  ./ui/correction.ui
                  

