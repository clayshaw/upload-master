project(big_int)

add_library(_big_int STATIC)

target_sources(_big_int
PRIVATE    
    ${CMAKE_CURRENT_SOURCE_DIR}/big_int.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/other.cpp
)

target_include_directories(_big_int
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../libbin)
