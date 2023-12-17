QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ecosystem.cpp \
    fish.cpp \
    gameobject.cpp \
    main.cpp \
    gamewindow.cpp \
    player.cpp \
    start.cpp \
    trash.cpp

HEADERS += \
    ecosystem.h \
    fish.h \
    gameobject.h \
    gamewindow.h \
    player.h \
    start.h \
    trash.h

FORMS += \
    gamewindow.ui \
    start.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    res.qrc
