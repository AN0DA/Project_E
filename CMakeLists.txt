#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.1) # personally I'd set this version as low as required; you don't have to require the cutting edge version

#how the project will be called
project (Project_E_2D)

#set include files
include_directories("${CMAKE_CURRENT_LIST_DIR}/SFML/include")

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 11)

#set source files
set (SOURCE_FILES main.cpp)

#look for SFML and add it
set(SFML_USE_STATIC_STD_LIBS TRUE)
set (SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/lib/cmake/SFML")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/lib/cmake/SFML/")
find_package (SFML REQUIRED audio network graphics window system)

include_directories(${SFML_INCLUDE_DIR})

#we add the executable of the program
add_executable (Project_E_2D ${SOURCE_FILES})
target_link_libraries(Project_E_2D ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(Project_E_2D sfml-audio sfml-network sfml-graphics sfml-window sfml-system   )
