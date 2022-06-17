project(big_int)

add_executable(big_int)

target_sources(big_int
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
)

target_link_libraries(big_int
PRIVATE
    _big_int
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../bin)