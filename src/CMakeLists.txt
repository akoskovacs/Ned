INCLUDE(${QT_USE_FILE})

SET(SOURCES
    main.cpp
    MainWindow.cpp
    FindDialog.cpp)

SET(HEADERS
    MainWindow.h
    FindDialog.h)

SET(RESOURCE
    ../Ned.qrc)

QT4_WRAP_CPP(MOCS ${SOURCES})
QT4_ADD_RESOURCES(RCC ${RESOURCE})

ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_EXECUTABLE(ned 
    ${SOURCES}
    ${MOCS}
    ${RCC})
TARGET_LINK_LIBRARIES(ned ${QT_LIBRARIES} pthread)
