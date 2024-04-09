cmake_minimum_required(VERSION 3.14)

# Project AggregatorCore
project(AggregatorCore LANGUAGES CXX)

# Default Qt Variables
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Paste components here
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Project variables
set(ENABLE_TESTING "Enables testing mode" ON)





# Compiler features
add_library(COMPILER_FEATURES INTERFACE)
target_compile_features(COMPILER_FEATURES 
  INTERFACE cxx_std_20
)

# Function to fast configuring
function(configure_target configureTarget)
  target_link_libraries(${configureTarget} 
    PRIVATE COMPILER_FEATURES
    PRIVATE Qt${QT_VERSION_MAJOR}::Core
  )
endfunction(configure_target)





# Project's target
add_subdirectory(AggregatorCore)





# CTest
if(ENABLE_TESTING)
  include(CTest)
endif()

# Subdirs
if(ENABLE_TESTING)
  add_subdirectory(external)
  add_subdirectory(tests)
endif()
