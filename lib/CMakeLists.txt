cmake_minimum_required(VERSION 2.8.11)

# Version
set(AMNESIA_CORE_MAJOR_VERSION 0)
set(AMNESIA_CORE_MINOR_VERSION 1)

# Use C99 standard
if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")
    endif ()
else ()
    set(CMAKE_C_STANDARD 99)
endif ()

project(${AMNESIA_CORE_NAME})
set(AMNESIA_CORE_VERSION "${AMNESIA_CORE_NAME}")

include_directories(
    ${AMNESIA_INCLUDE_DIRS}
)

# Source files
set(AMNESIA_CORE_SRC
    amnesia.c
)

# Save me from manually including the files ;)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Configure a header file to pass some of the CMake settings
# to the source code
#configure_file(
#    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
#    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
#)

# Specify the library to be built
add_library(${AMNESIA_CORE_NAME} STATIC ${AMNESIA_CORE_SRC})
