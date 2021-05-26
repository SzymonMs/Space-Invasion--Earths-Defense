TEMPLATE = app
CONFIG += console c++7
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        airplane.cpp \
        alien.cpp \
        background.cpp \
        bomb.cpp \
        button.cpp \
        game.cpp \
        include.cpp \
        main.cpp
INCLUDEPATH += "C:/SFML/include"
LIBS += -L"C:/SFML/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    airplane.h \
    alien.h \
    background.h \
    bomb.h \
    button.h \
    game.h \
    include.h
