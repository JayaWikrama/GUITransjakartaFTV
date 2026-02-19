#-------------------------------------------------
#
# Project created by QtCreator 2025-11-30T16:00:47
#
#-------------------------------------------------

QT       += widgets

TARGET = gui
TEMPLATE = lib

DEFINES += GUI_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/gui.cpp \
        src/mainwindow.cpp \
        src/label.cpp \
        src/transaction-counter.cpp \
        src/transaction-pending-summary.cpp \
    src/message.cpp \
    src/container.cpp \
    src/network-icon.cpp

HEADERS += \
        include/gui.hpp \
        include/mainwindow.hpp \
        include/label.hpp \
        include/transaction-counter.hpp \
        include/transaction-pending-summary.hpp \
    include/message.hpp \
    include/container.hpp \
    include/network-icon.hpp

FORMS += \
        mainwindow.ui

RESOURCES += resources.qrc

INCLUDEPATH += $$PWD/include

unix {
    target.path = /usr/lib
    INSTALLS += target
}
