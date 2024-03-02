QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../backend/s21_connect.c \
    ../backend/s21_credit_calc.c \
    ../backend/s21_from_postfix_to_result.c \
    ../backend/s21_to_postfix.c \
    ../qcustom/qcustomplot.cpp \
    contribution_calc.cpp \
    credit_calc.cpp \
    graph_window.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../backend/s21_calc.h \
    ../qcustom/qcustomplot.h \
    contribution_calc.h \
    credit_calc.h \
    graph_window.h \
    mainwindow.h

FORMS += \
    contribution_calc.ui \
    credit_calc.ui \
    graph_window.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
