macro(build_googletest _gtest_root )
    configure_file(
            ${_gtest_root}/CMakeLists.txt
            @ONLY
    )
    execute_process(
        COMMAND
            "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}"
        WORKING_DIRECTORY
            ${_gtest_root}
    )

    execute_process(
        COMMAND
            "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY
            ${_gtest_root}
    )


endmacro()