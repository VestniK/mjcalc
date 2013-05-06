cmake_minimum_required(VERSION 2.6)

set(mjcalc_SRCS
  hand.cpp
  persistantstore.cpp
  resultstorage.cpp
  mjcalcview.cpp
  game.cpp
  round.cpp
  result.cpp
)
set(mjcalc_MOC_HDRS
  hand.h
  resultstorage.h
  mjcalcview.h
  game.h
  round.h
)
set(TS_SRC_local
  ${mjcalc_SRCS}
  ${mjcalc_MOC_HDRS}
  persistantstore.h
  result.h
)
foreach (src ${TS_SRC_local})
  list(APPEND TS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/${src}")
endforeach(src)
set(TS_SRC ${TS_SRC} PARENT_SCOPE)

qt4_wrap_cpp(mjcalc_MOC ${mjcalc_MOC_HDRS})
add_library(MjcalcEngine STATIC ${mjcalc_SRCS} ${mjcalc_MOC})
