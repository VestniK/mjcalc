cmake_minimum_required(VERSION 2.6)

set(mjcalc_SRCS
  resultstorage.cpp
  mjcalcview.cpp
  game.cpp
  round.cpp
  result.cpp
)
set(mjcalc_MOC_HDRS
  resultstorage.h
  mjcalcview.h
  game.h
  round.h
)

qt4_wrap_cpp(mjcalc_MOC ${mjcalc_MOC_HDRS})
add_library(MjcalcEngine STATIC ${mjcalc_SRCS} ${mjcalc_MOC})
