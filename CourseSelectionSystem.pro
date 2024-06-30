QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    course.cpp \
    filter.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    teacher.cpp \
    user.cpp

HEADERS += \
    admin.h \
    course.h \
    filter.h \
    login.h \
    mainwindow.h \
    student.h \
    teacher.h \
    user.h

FORMS += \
    admin.ui \
    login.ui \
    mainwindow.ui \
    student.ui \
    teacher.ui \
    user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target