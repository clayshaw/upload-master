project(matrix)

add_executable(matrix)
add_library(_matrix STATIC)

target_sources(matrix
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/matrix.cpp
)

target_sources(_matrix
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/matrix.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../libbin)