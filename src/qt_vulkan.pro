QT += core gui qml widgets quick charts svg
CONFIG += c++17
DEFINES +=

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050A00    # 5.10

QMAKE_CXXFLAGS_WARN_OFF -= -Wmismatched-tags

HEADERS += \
    compatibility.h \
    mainwindow.h \
    common/backgroundworker.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    common/backgroundworker.cpp

TRANSLATIONS += \
    resources/translations/en_US.ts \
    resources/translations/nl_NL.ts

RESOURCES += qml.qrc \
    fonts.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

# RC_ICONS = app.ico

# ICON = app.icns
