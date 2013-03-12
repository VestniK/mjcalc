cmake_minimum_required(VERSION 2.6)

set(mjcalc_SRCS
  resultstorage.cpp
  mjcalcview.cpp
  game.cpp
  round.cpp
  mjcalc.cpp
  result.cpp
)
set(mjcalc_MOC_HDRS
  resultstorage.h
  mjcalcview.h
  game.h
  round.h
)

qt4_wrap_cpp(mjcalc_MOC ${mjcalc_MOC_HDRS})
add_executable(mjcalc ${mjcalc_SRCS} ${mjcalc_MOC})
target_link_libraries(mjcalc ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTDECLARATIVE_LIBRARY})
