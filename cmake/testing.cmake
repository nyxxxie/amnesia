macro(CREATE_TEST TARGET_NAME)
    set(options COPYFILES)
    set(oneval)
    set(multivals LIBS SRC)
    cmake_parse_arguments(ARG "${options}" "${oneval}" "${multivals}" ${ARGN} )

    set(TEST_TARGET test_${TARGET_NAME})
    add_executable(${TEST_TARGET} ${ARG_SRC})
    add_dependencies(${TEST_BUILD_TARGET} ${TEST_TARGET})
    target_link_libraries(${TEST_TARGET} ${ARG_LIBS} gtest)

    if (${ARG_COPYFILES})
        add_custom_target(${TEST_TARGET}_copy_files
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_LIST_DIR}/res ${CMAKE_CURRENT_BINARY_DIR}/res)
        add_dependencies(${TEST_TARGET} ${TEST_TARGET}_copy_files)
    endif ()

    add_test(${TEST_TARGET} ${TEST_TARGET})
endmacro()
