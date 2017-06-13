CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )
project( bataille_navale )
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14 ${CMAKE_CXX_FLAGS} ")
find_package( PkgConfig REQUIRED )
#pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(MYPKG REQUIRED cpputest)
#pkg_check_modules(MYPKG REQUIRED cpputest gtkmm-3.0)

#link_directories(${GTKMM_LIBRARY_DIRS})
#include_directories( ${GTKMM_INCLUDE_DIRS} )
link_directories(${MYPKG_LIBRARY_DIRS})
include_directories(${MYPKG_INCLUDE_DIRS})

find_package(SFML REQUIRED)

ADD_EXECUTABLE( bataille.out src/bataille.cpp
  src/Plateau.cpp
  src/Bateau.cpp
  src/Coup.cpp
  src/Joueur.cpp
  )

ADD_EXECUTABLE( fenetre.out src/menuPrincipal.cpp 
							src/menuDifficulte.cpp
							src/menuOptions.cpp
							src/menuJouer.cpp)

ADD_EXECUTABLE( main_test.out src/main_test.cpp)

target_link_libraries( bataille.out ${MYPKG_LIBRARIES} )
target_link_libraries( fenetre.out ${SFML_LIBRARY} )
target_link_libraries( main_test.out ${MYPKG_LIBRARIES} )

install (TARGETS bataille.out DESTINATION bin)
