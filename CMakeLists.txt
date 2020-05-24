#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.2) # personally I'd set this version as low as required; you don't have to require the cutting edge version

#how the project will be called
project (Project_E_2D)

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build type." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

if(NOT SFML_ROOT)
  set(SFML_ROOT CACHE "" FORCE)
endif()

# Find SFML
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if(NOT SFML_FOUND)
  message(FATAL_ERROR "SFML couldn't be located!")
endif()


#set include files
include_directories(${SFML_INCLUDE_DIR})



#set source files
set(SOURCE_FILES src/*.cpp)

#we add the executable of the program
add_executable(Project_2D_E ${SOURCE_FILES})

target_link_libraries(Project_2D_E ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

