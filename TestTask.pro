QT       += core gui sql charts

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
    bar_series_creator.cpp \
    config_reader.cpp \
    graphic_model_creator.cpp \
    imodel_creator.cpp \
    iseries_creator.cpp \
    main.cpp \
    mainwindow.cpp \
    spline_series_creator.cpp \
    sql_driver.cpp \
    table_names_model_creator.cpp \
    table_values_model_creator.cpp

HEADERS += \
    bar_series_creator.h \
    config_reader.h \
    graphic_model_creator.h \
    imodel_creator.h \
    iseries_creator.h \
    mainwindow.h \
    spline_series_creator.h \
    sql_driver.h \
    table_names_model_creator.h \
    table_values_model_creator.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    TestTaskResources.qrc
