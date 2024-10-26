QT += gui core widgets

SOURCES += ejemplo1.cpp
TARGET = ejemplo1

INCLUDEPATH += /usr/include/opencv4 

LIBS += -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio
