TEMPLATE = app
TARGET = server_app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += TEST

HEADERS += \
    CBaseSpaceObject.h \
    CCalc.h \
    CConfig.h \
    CCoords.h \
    CExceptions.h \
    CRotate.h \
    IMovable.h \
    IMove.h \
    IRotate.h \
    Move/CLinearMove.h \
    Move/CMove.h \
    Move/IMovable.h \
    Rotate/CRotate.h \
    Rotate/IRotable.h \
    test/CTestObjectMovable.h \
    test/CTestObjectRotable.h \
    test/test.h

SOURCES += \
    CBaseSpaceObject.cpp \
    Move/IMovable.cpp \
    main.cpp

LIBS += -lcppunit
