set(QMLS
  main.qml
)

foreach(_qml ${QMLS})
  get_filename_component(qml_name ${_qml} NAME)
  configure_file(${_qml} ${CMAKE_APPDATA_OUTPUT_DIRECTORY}/${qml_name} COPYONLY)
endforeach()
