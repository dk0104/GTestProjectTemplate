cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
add_library(src "")


set(SOURCE_FILES
        HouseRobberyMemoization.cpp
        matrixSquareFinder.cpp
        unsortStuff.cpp
)

set(HEADER_FILES
        HouseRobberyMemoization.hpp
        matrixSquareFinder.hpp
        unsortSruff.hpp
)


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