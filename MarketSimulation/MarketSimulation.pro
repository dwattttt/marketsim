#-------------------------------------------------
#
# Project created by QtCreator 2012-07-29T13:34:25
#
#-------------------------------------------------

QT       += core gui

TARGET = MarketSimulation
TEMPLATE = app
DEFINES += QWT_DLL

SOURCES += main.cpp\
        mainwindow.cpp \
    market.cpp \
    simulationwindow.cpp \
    titlescreen.cpp \
    instructionscreen1.cpp \
    instructionscreen2.cpp \
    instructionscreen3.cpp \
    instructionscreentest1.cpp \
    instructionscreentest2.cpp \
    instructionscreen4.cpp \
    instructionscreen5.cpp \
    instructionscreen6.cpp \
    instructionscreen7.cpp \
    instructionscreentest3.cpp \
    instructionscreen8.cpp \
    decryptionwindow.cpp \
    initialallocationscreen.cpp \
    quest1.cpp \
    finalscreen.cpp \
    decrypt/wordlist.cpp \
    decrypt/substitutioncipher.cpp \
    decrypt/guessinput.cpp \
    plotwidget.cpp \
    circularbuffer.cpp \
    QPictureLabel.cpp

HEADERS  += mainwindow.h \
    market.h \
    simulationwindow.h \
    titlescreen.h \
    instructionscreen1.h \
    instructionscreen2.h \
    instructionscreen3.h \
    instructionscreentest1.h \
    instructionscreentest2.h \
    instructionscreen4.h \
    instructionscreen5.h \
    instructionscreen6.h \
    instructionscreen7.h \
    instructionscreentest3.h \
    instructionscreen8.h \
    decryptionwindow.h \
    initialallocationscreen.h \
    quest1.h \
    finalscreen.h \
    decrypt/wordlist.h \
    decrypt/substitutioncipher.h \
    decrypt/guessinput.h \
    plotwidget.h \
    circularbuffer.h \
    QPictureLabel.hpp

FORMS    += mainwindow.ui \
    simulationwindow.ui \
    titlescreen.ui \
    instructionscreen1.ui \
    instructionscreen2.ui \
    instructionscreen3.ui \
    instructionscreentest1.ui \
    instructionscreentest2.ui \
    instructionscreen4.ui \
    instructionscreen5.ui \
    instructionscreen6.ui \
    instructionscreen7.ui \
    instructionscreentest3.ui \
    instructionscreen8.ui \
    decryptionwindow.ui \
    initialallocationscreen.ui \
    quest1.ui \
    finalscreen.ui \
    plotwidget.ui

RESOURCES += \
    resources.qrc

Debug {
    LIBS += -L../Qwt/lib -lqwtd
}

Release {
    LIBS +=  -L../Qwt/lib -lqwt
}

INCLUDEPATH +=../Qwt/include
