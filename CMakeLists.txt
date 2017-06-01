CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )
project( bataille_navale )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_BUILD_TYPE Debug )

set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14 ${CMAKE_CXX_FLAGS} ")

find_package( PkgConfig REQUIRED )
pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(MYPKG REQUIRED cpputest)

#pkg_check_modules(MYPKG REQUIRED cpputest gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories( ${GTKMM_INCLUDE_DIRS} )

link_directories(${MYPKG_LIBRARY_DIRS})
include_directories(${MYPKG_INCLUDE_DIRS}) 

ADD_EXECUTABLE( bataille.out src/bataille.cpp src/Plateau.cpp)

ADD_EXECUTABLE( fenetre.out src/ig.cpp)

<<<<<<< HEAD
=======
ADD_EXECUTABLE( bataille.out src/bataille.cpp
  src/Plateau.cpp)

>>>>>>> cb301f27e886bd4d2ee9c664dfa52193682a77b7
ADD_EXECUTABLE( main_test.out src/main_test.cpp)

target_link_libraries( bataille.out ${GTKMM_LIBRARIES} )
target_link_libraries( fenetre.out ${GTKMM_LIBRARIES} )
target_link_libraries( main_test.out ${MYPKG_LIBRARIES} )

install (TARGETS bataille.out DESTINATION bin)
