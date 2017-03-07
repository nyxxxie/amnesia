cmake_minimum_required(VERSION 2.8.11)

# Save me from manually including the files ;)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Configure a header file to pass some of the CMake settings
# to the source code
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
)

add_executable(${AMNESIA_TEST_CLIENT_NAME} main.c)
add_dependencies(${AMNESIA_TEST_CLIENT_NAME} ${AMNESIA_CORE_NAME})
target_link_libraries(${AMNESIA_TEST_CLIENT_NAME} ${AMNESIA_CORE_NAME})
