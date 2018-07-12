cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
add_library(src "")


set(SOURCE_FILES
        HouseRobberyMemorization.cpp

)

set(HEADER_FILES
        HouseRobberyMemorization.hpp

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