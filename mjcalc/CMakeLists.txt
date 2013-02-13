cmake_minimum_required(VERSION 2.6)

set(mjcalc_SRCS
  resultcontroller.cpp
  mjcalc.cpp
  roundresult.cpp
)
set(mjcalc_MOC_HDRS
  resultcontroller.h
)

qt4_wrap_cpp(mjcalc_MOC ${mjcalc_MOC_HDRS})
add_executable(mjcalc ${mjcalc_SRCS} ${mjcalc_MOC})
target_link_libraries(mjcalc ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTDECLARATIVE_LIBRARY})
