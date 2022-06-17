project(vector)

add_executable(vector)
add_library(_vector STATIC)

target_sources(vector
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vector.cpp
)

target_sources(_vector
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vector.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../libbin)