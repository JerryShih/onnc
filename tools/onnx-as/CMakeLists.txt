
include_directories(${ONNX_INCLUDE_DIRS})
include_directories(${ONNC_INCLUDE_DIRS})

add_executable(onnx-as main.cpp)
target_link_libraries(onnx-as
    ${ONNX_LIBRARIES}
    ${PROTOBUF_LIBRARIES}
    libonnc)

install(TARGETS onnx-as
    RUNTIME DESTINATION bin)
