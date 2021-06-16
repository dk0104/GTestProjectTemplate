cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(gtestprojectTemplate CXX)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})


option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing : ${ENABLE_UNIT_TESTS}")

if(ENABLE_UNIT_TESTS)
        include(FetchContent)
        FetchContent_Declare(
                googletest
                GIT_REPOSITORY https://github.com/google/googletest.git
                GIT_TAG release-1.8.1
        )
        FetchContent_GetProperties(googletest)

        if(NOT googletest_POPULATED)
                FetchContent_Populate(googletest)
                # Prevent GoogleTest from overriding our compiler/linker options
                # when building with Visual Studio
                set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
                # Prevent GoogleTest from using PThreads
                set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
                add_subdirectory(
                        ${googletest_SOURCE_DIR}
                        ${googletest_BINARY_DIR}
                )
                # Silence std::tr1 warning on MSVC
                if(MSVC)
                        foreach(_tgt gtest gtest_main gmock gmock_main)
                                target_compile_definitions(${_tgt}
                                PRIVATE
                                "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
                                )
                        endforeach()
                endif()
        endif()
endif()

add_subdirectory(src)
add_subdirectory(test)
