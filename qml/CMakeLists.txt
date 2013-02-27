set(QMLS
# Pages
  new.qml
  addResults.qml
# Atomic components
  Background.qml
  TextButton.qml
  LineEdit.qml
# Reusable combinations
  ScoreInput.qml
  NameInput.qml
# Global UI style constants
  Style.qml
# Images
  rdragon.svg
  east.svg
  south.svg
  west.svg
  north.svg
  winner.svg
)

foreach(_qml ${QMLS})
  get_filename_component(qml_name ${_qml} NAME)
  configure_file(${_qml} ${CMAKE_APPDATA_OUTPUT_DIRECTORY}/${qml_name} COPYONLY)
endforeach()
