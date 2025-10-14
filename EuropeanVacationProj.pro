QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admincitiesedit.cpp \
    adminfoodedit.cpp \
    adminloginwindow.cpp \
    adminmainwindow.cpp \
    adminutilities.cpp \
    checkoutdialog.cpp \
    confirmselectedcities.cpp \
    guestmainwindow.cpp \
    guestwcustom1.cpp \
    guestwcustom2.cpp \
    guestwcustom3.cpp \
    guestwcustom4.cpp \
    guestwplanned1.cpp \
    loadCities.cpp \
    londonwindow1.cpp \
    main.cpp \
    mainwindow.cpp \
    pariswindow1.cpp

HEADERS += \
    admincitiesedit.h \
    adminfoodedit.h \
    adminloginwindow.h \
    adminmainwindow.h \
    adminutilities.h \
    checkoutdialog.h \
    confirmselectedcities.h \
    guestmainwindow.h \
    guestwcustom1.h \
    guestwcustom2.h \
    guestwcustom3.h \
    guestwcustom4.h \
    guestwplanned1.h \
    loadCities.h \
    londonwindow1.h \
    mainwindow.h \
    pariswindow1.h

FORMS += \
    admincitiesedit.ui \
    adminfoodedit.ui \
    adminloginwindow.ui \
    adminmainwindow.ui \
    checkoutdialog.ui \
    confirmselectedcities.ui \
    guestmainwindow.ui \
    guestwcustom1.ui \
    guestwcustom2.ui \
    guestwcustom3.ui \
    guestwcustom4.ui \
    guestwplanned1.ui \
    londonwindow1.ui \
    mainwindow.ui \
    pariswindow1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    admin.txt \
    distances.txt \
    foods.txt \
    new_cities.txt
