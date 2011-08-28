project(mjcalc)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 COMPONENTS QtCore QtGui QtDeclarative REQUIRED)
include(${QT_USE_FILE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_APPDATA_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/${CMAKE_PROJECT_NAME})
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${mjcalc_SOURCE_DIR})

add_subdirectory(mjcalc)
add_subdirectory(qml)