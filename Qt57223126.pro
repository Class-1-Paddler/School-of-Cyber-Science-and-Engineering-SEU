QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filterDlg.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    playerTableModel.cpp \
    searchDlg.cpp \
    sessionTableModel.cpp \
    sessionmessageDlg.cpp

HEADERS += \
    dataClass.h \
    filterDlg.h \
    global.h \
    mainwindow.h \
    playerTableModel.h \
    searchDlg.h \
    sessionTableModel.h \
    sessionmessageDlg.h

FORMS += \
    filterDlg.ui \
    mainwindow.ui \
    searchDlg.ui \
    sessionmessageDlg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resouse.qrc
