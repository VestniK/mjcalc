qt4_create_translation(mjcalc-ru_RU.qm ${TS_SRC} mjcalc-ru_RU.ts)
add_custom_target(translate
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/mjcalc-ru_RU.qm ${CMAKE_APPDATA_OUTPUT_DIRECTORY}
  DEPENDS mjcalc-ru_RU.qm
)
