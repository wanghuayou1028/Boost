cmake_minimum_required( VERSION 2.8 )
project( boost_learning )

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable( lexical_cast lexical_cast.cpp )
target_link_libraries(lexical_cast ${Boost_LIBRARIES}) 

add_executable( scoped_ptr scoped_ptr.cpp )
target_link_libraries(scoped_ptr ${Boost_LIBRARIES}) 

add_executable( shared_ptr shared_ptr.cpp )
target_link_libraries(shared_ptr ${Boost_LIBRARIES}) 