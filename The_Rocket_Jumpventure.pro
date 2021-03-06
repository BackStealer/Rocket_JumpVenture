QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Airblasted.cpp \
    Blu_bots.cpp \
    Game.cpp \
    Health.cpp \
    HeavyBot.cpp \
    Intel.cpp \
    Pyro.cpp \
    Rocket.cpp \
    Score.cpp \
    Skill.cpp \
    Soldier.cpp \
    main.cpp

HEADERS += \
    Airblasted.h \
    Blu_bots.h \
    Game.h \
    Health.h \
    HeavyBot.h \
    Intel.h \
    Pyro.h \
    Rocket.h \
    Score.h \
    Skill.h \
    Soldier.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
