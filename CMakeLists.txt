cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(gtestprojectTemplate CXX)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})


add_subdirectory(src)
add_subdirectory(googletest)

include(test/googletest.cmake)
build_googletest(
        ${PROJECT_SOURCE_DIR}/googletest
)

add_subdirectory(test)
