add_executable(unit_tests
    UnsortStuffTest.cpp
    HouseRobberyTest.cpp
    MatrixSquareFinderTest.cpp
)

target_link_libraries(unit_tests
    src
    gtest
    gtest_main
)

add_test(
    NAME
     UnitTests
    COMMAND
    ${CMAKE_BINARY_DIR}/{CMAKE_INSTALL_BINDIR}/unit_tests 
)
