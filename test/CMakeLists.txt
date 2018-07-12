set(GTEST_ROOT "/opt/googletest/googletest")
enable_testing()
find_package(GTest REQUIRED)

add_executable(unit_tests

)

target_link_libraries(unit_tests
    GTest::GTest 
    GTest::Main 
    src
)

add_test(
    NAME
     UnitTests
    CMAKE_COMMAND
    ${CMAKE_BINARY_DIR}/{CMAKE_INSTALL_BINDIR}/unit_tests 
)