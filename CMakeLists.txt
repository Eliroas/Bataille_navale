CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )
project( bataille_navale )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_BUILD_TYPE Debug )

set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14 ${CMAKE_CXX_FLAGS} ")

find_package( PkgConfig REQUIRED )
include_directories( ${MYPKG_INCLUDE_DIRS} )

ADD_EXECUTABLE( bataille.out src/bataille.cpp)

target_link_libraries( bataille.out ${MYPKG_LIBRARIES} )

install (TARGETS bataille.out DESTINATION bin)
