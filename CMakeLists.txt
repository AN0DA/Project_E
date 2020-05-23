#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.1) # personally I'd set this version as low as required; you don't have to require the cutting edge version

#how the project will be called
project (project_e)

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 11)

#set source files
set (SOURCE_FILES main.cpp)

#look for SFML and add it
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake-modules/")
set (SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/lib/cmake/SFML")
find_package (SFML REQUIRED system window graphics network audio)

include_directories(${SFML_INCLUDE_DIR})

#we add the executable of the program
add_executable (project_e ${SOURCE_FILES})
target_link_libraries(project_e ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
