######################################################################
# Automatically generated by qmake (2.01a) Wed Nov 21 12:25:03 2013
######################################################################

QT += core gui widgets \
        multimedia

TEMPLATE = app

TARGET = gomoku

# Input
HEADERS += mainwindow.h \
    IA.hh \
    Gomoku.h

FORMS += mainwindow.ui

SOURCES +=	main.cpp\
			mainwindow.cpp \
    Win.cpp \
    Taken.cpp \
    IA_Eval.cpp \
    IA.cpp \
    Double_Trois.cpp

OTHER_FILES += \
			LICENSE\
			images/gomoku.png\
			images/cross.png\
			images/circle.png

