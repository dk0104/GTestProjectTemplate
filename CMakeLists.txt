cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(gtestprojectTemplate CXX)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})


add_subdirectory(src)
enable_testing()
add_subdirectory(test)
add_subdirectory(googletest)

include(test/googletest.cmake)
build_googletest(
        ${PROJECT_SOURCE_DIR}/googletest
)

