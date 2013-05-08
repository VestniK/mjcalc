set(QMLS
# Pages
  new.qml
  addResults.qml
  main.qml
# Atomic components
  Background.qml
  TextButton.qml
  LineEdit.qml
  MessageBox.qml
  Pannel.qml
  PannelButton.qml
# Reusable combinations
  ScoreInput.qml
  NameInput.qml
  ResultsRow.qml
# Global UI style constants
  Style.qml
)
set(IMGS
# Images
  rdragon.svg
  east.svg
  south.svg
  west.svg
  north.svg
  winner.svg
  normalHand.svg
  deadHand.svg
# Buttons
  add.svg
  new.svg
  back.svg
)
foreach (src ${QMLS})
  list(APPEND TS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/${src}")
endforeach(src)
set(TS_SRC ${TS_SRC} PARENT_SCOPE)

foreach(_qml ${QMLS} ${IMGS})
  get_filename_component(qml_name ${_qml} NAME)
  configure_file(${_qml} ${CMAKE_APPDATA_OUTPUT_DIRECTORY}/${qml_name} COPYONLY)
endforeach()
