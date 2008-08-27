TEMPLATE = app
TARGET   = qVanHeartRate


QT += network
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
           model/parser/gpxwriter.cpp
                      
HEADERS  = \
           view/mainwindow.h \
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
           model/parser/gpxwriter.h

FORMS = \

#RESOURCES= src.qrc

