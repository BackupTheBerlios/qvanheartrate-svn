TEMPLATE = app
TARGET   = qVanHeartRate


QT += network 
#QT += webkit
CONFIG += debug qtestlib 

INCLUDEPATH += .

#TRANSLATIONS = src_de.ts \

MOC_DIR=_qbuild_/moc
OBJECTS_DIR=_qbuild_/obj
RCC_DIR=_qbuild_/obj
UI_DIR =_qbuild_/ui

SOURCES  = \
           main.cpp  \
           view/mainwindow.cpp \
           view/graphicsview/mapwidget.cpp \
           view/graphicsview/curvewidget.cpp \
           model/modelcontroller.cpp \
           model/elements/activities.cpp \
           model/elements/activity.cpp \
           model/elements/author.cpp \
           model/elements/creator.cpp \
           model/elements/lap.cpp \
           model/elements/track.cpp \
           model/elements/trackpoint.cpp \
           model/elements/position.cpp \
           model/parser/tcxreader.cpp \
           model/parser/gpxwriter.cpp \
           model/statistics/statistic.cpp
                      
HEADERS  = \
           view/mainwindow.h \
           view/graphicsview/mapwidget.h \
           view/graphicsview/curvewidget.h \
           model/modelcontroller.h \
           model/elements/activities.h \
           model/elements/activity.h \
           model/elements/author.h \
           model/elements/creator.h \
           model/elements/lap.h \
           model/elements/track.h \
           model/elements/trackpoint.h \
           model/elements/position.h \
           model/parser/tcxreader.h \
           model/parser/gpxwriter.h \
           model/statistics/statistic.h

FORMS = view/mainwindow.ui \

#RESOURCES= src.qrc

