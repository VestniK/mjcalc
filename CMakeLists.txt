project(mjcalc)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 COMPONENTS QtCore QtGui QtDeclarative REQUIRED)
include(${QT_USE_FILE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_APPDATA_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/${CMAKE_PROJECT_NAME})
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${mjcalc_SOURCE_DIR})

add_subdirectory(mjcalc)
add_subdirectory(qml)

add_executable(mjcalc mjcalc.cpp)
target_link_libraries(mjcalc ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTDECLARATIVE_LIBRARY} MjcalcEngine)

if (BLACKBERRY)
  find_program(RSVG_CONVERT NAMES rsvg-convert)
  find_program(BB_PACKAGER NAMES blackberry-nativepackager)

  add_custom_command(OUTPUT icon.png DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/icon.svg
    COMMAND ${RSVG_CONVERT} -w 86 -h 86 -f png ${CMAKE_CURRENT_SOURCE_DIR}/icon.svg -o ${CMAKE_CURRENT_BINARY_DIR}/icon.png
  )

  if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    if(NOT DEFINED DEBUG_TOKEN)
      message(FATAL_ERROR "Debug Blackberry build without debug token. Set DEBUG_TOKEN variable to full path to the valid debug token.")
    endif(NOT DEFINED DEBUG_TOKEN)
    set(DEV_FLAGS -devMode -debugToken ${DEBUG_TOKEN})
  endif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")

  add_custom_command(OUTPUT mjcalc.bar DEPENDS icon.png mjcalc ${CMAKE_CURRENT_SOURCE_DIR}/bar-descriptor.xml
    COMMAND ${BB_PACKAGER} -package ${CMAKE_CURRENT_BINARY_DIR}/mjcalc.bar -D BUILD_DIR=${CMAKE_CURRENT_BINARY_DIR} -D QT4_DIR=$ENV{QT_DIR} ${DEV_FLAGS} ${CMAKE_CURRENT_SOURCE_DIR}/bar-descriptor.xml
  )
  add_custom_target(package DEPENDS mjcalc.bar)
endif(BLACKBERRY)
