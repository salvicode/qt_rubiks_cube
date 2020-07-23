cmake_minimum_required(VERSION 3.5)

project(QtRubiksCube LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

# Suppress warnings of the deprecation of glut functions on macOS.
if(APPLE)
 add_definitions(-Wno-deprecated-declarations)
endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# OPENGL_INCLUDE_DIR, GLUT_INCLUDE_DIR, OPENGL_LIBRARIES, and GLUT_LIBRARIES are CMake built-in variables defined when the packages are found.
set(INCLUDE_DIRS ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})
set(LIBRARIES ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
# If not on macOS, add glew include directory and library path to lists.
if(UNIX AND NOT APPLE)
 list(APPEND INCLUDE_DIRS ${GLEW_INCLUDE_DIRS})
 list(APPEND LIBRARIES ${GLEW_LIBRARIES})
endif()

set(TS_FILES QtRubiksCube_es_ES.ts)

if(ANDROID)
  add_library(QtRubiksCube SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    rubiksopenglwidget.h
    rubiksopenglwidget.cpp
    mathutils.h
    mathutils.cpp
    colorutils.h
    colorutils.cpp
    ${TS_FILES}
  )
else()
  add_executable(QtRubiksCube
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    rubiksopenglwidget.h
    rubiksopenglwidget.cpp
    mathutils.h
    mathutils.cpp
    colorutils.h
    colorutils.cpp
    ${TS_FILES}
  )
endif()

target_link_libraries(QtRubiksCube PRIVATE Qt5::Widgets ${LIBRARIES})

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
