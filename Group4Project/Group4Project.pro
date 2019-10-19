QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    member.cpp \
    preferredmember.cpp \
    sales.cpp \
    wholesaleclub.cpp

HEADERS += \
    container.h \
    item.h \
    mainwindow.h \
    member.h \
    preferredmember.h \
    sales.h \
    wholesaleclub.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    forLogos.qrc

DISTFILES += \
    ../build-Group4Project-Desktop_Qt_5_13_1_clang_64bit-Debug/day1.txt \
    ../build-Group4Project-Desktop_Qt_5_13_1_clang_64bit-Debug/day2.txt \
    ../build-Group4Project-Desktop_Qt_5_13_1_clang_64bit-Debug/day3.txt \
    ../build-Group4Project-Desktop_Qt_5_13_1_clang_64bit-Debug/day4.txt \
    ../build-Group4Project-Desktop_Qt_5_13_1_clang_64bit-Debug/day5.txt \
    ../build-Group4Project-Desktop_Qt_5_13_1_clang_64bit-Debug/warehouse shoppers.txt \
    DaySalesTxtFiles/day1.txt \
    DaySalesTxtFiles/day2.txt \
    DaySalesTxtFiles/day3.txt \
    DaySalesTxtFiles/day4.txt \
    DaySalesTxtFiles/day5.txt \
    WarehouseMembersInfoTxt/warehouse shoppers.txt
