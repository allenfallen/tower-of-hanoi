TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shader/shader.cpp \
    board/towerofhanoi.cpp


LIBS += -L"/home/allen/SFML/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/allen/SFML/include"
DEPENDPATH += "/home/allen/SFML/include"

HEADERS += \
    shader/shader.h \
    board/towerofhanoi.h

