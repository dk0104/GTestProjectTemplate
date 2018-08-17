cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
add_library(src "")


set(SOURCE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/HouseRobberyMemoization.cpp
        ${CMAKE_CURRENT_LIST_DIR}/matrixSquareFinder.cpp
        ${CMAKE_CURRENT_LIST_DIR}/unsortStuff.cpp
)

set(HEADER_FILES
        ${CMAKE_CURRENT_LIST_DIR}/HouseRobberyMemoization.hpp
        ${CMAKE_CURRENT_LIST_DIR}/matrixSquareFinder.hpp
        ${CMAKE_CURRENT_LIST_DIR}/unsortSruff.hpp
)
message(STATUS "SOURCES" ${SOURCE_FILES})

target_sources(src
    PRIVATE  
        ${SOURCE_FILES}
    PUBLIC
        ${HEADER_FILES}
    )

target_include_directories(src
   PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}
)    
