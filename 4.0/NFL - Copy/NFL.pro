QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    customrecursiontrip.cpp \
    customtrip.cpp \
    customtrip_2.cpp \
    database.cpp \
    displayteam.cpp \
    graphtraversal.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    newengland.cpp \
    traversals.cpp \
    user.cpp

HEADERS += \
    admin.h \
    customrecursiontrip.h \
    customtrip.h \
    customtrip_2.h \
    database.h \
    displayteam.h \
    graphtraversal.h \
    login.h \
    mainwindow.h \
    newengland.h \
    traversals.h \
    user.h

FORMS += \
    admin.ui \
    customrecursiontrip.ui \
    customtrip.ui \
    customtrip_2.ui \
    displayteam.ui \
    graphtraversal.ui \
    login.ui \
    mainwindow.ui \
    newengland.ui \
    user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
