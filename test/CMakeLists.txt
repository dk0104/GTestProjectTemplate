enable_testing()

add_executable(unit_tests
    HouseRobberyTest.cpp
    MatrixSquareFinderTest.cpp
)

target_link_libraries(unit_tests
    gtest
    gtest_main
    src
)

add_test(
    NAME
     UnitTests
    COMMAND
    ${CMAKE_BINARY_DIR}/{CMAKE_INSTALL_BINDIR}/unit_tests 
)