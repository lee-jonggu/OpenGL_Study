QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

LIBS += -lopengl32 -lglu32 -lfreeglut -LC:\ProgramFiles(x86)\MicrosoftVisualStudio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
