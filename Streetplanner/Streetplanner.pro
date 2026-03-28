QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000     # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DialogAddCity.cpp \
    main.cpp \
    mainwindow.cpp \
    city.cpp \
    street.cpp \
    map.cpp \
    abstractmap.cpp \
    mapio.cpp \
    mapionrw.cpp \
    dijkstra.cpp \
    DialogAddStreet.cpp

HEADERS += \
    mainwindow.h \
    city.h \
    street.h \
    map.h \
    abstractmap.h \
    mapio.h \
    mapionrw.h \
    dijkstra.h \
    DialogAddCity.h \
    mapiofileinput.h\
    DialogAddStreet.h

FORMS += \
    mainwindow.ui \
    DialogAddStreet.ui \
    DialogAddCity.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
