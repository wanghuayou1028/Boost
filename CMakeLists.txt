cmake_minimum_required( VERSION 2.8 )
project( lexical_cast )

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable( lexical_cast lexical_cast.cpp )
target_link_libraries(lexical_cast ${Boost_LIBRARIES}) 
