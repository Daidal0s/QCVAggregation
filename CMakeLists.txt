### Delete after template ###
# Project template word - PLACEHOLDER
# Class template word - pLACEHOLDER
### Delete after template ###

cmake_minimum_required(VERSION 3.14)

# Project PLACEHOLDER
project(PLACEHOLDER LANGUAGES CXX)

# Default Qt Variables
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Project variables
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/headers)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS_INLUDES ${HEADERS_DIR}/pLACEHOLDER.h)

# Source to compile
set(PROJECT_SOURCES
  ${SOURCE_DIR}/pLACEHOLDER.cpp
)

# Paste components here
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Compiler features
add_library(COMPILER_FEATURES INTERFACE)
target_compile_features(COMPILER_FEATURES 
  INTERFACE cxx_std_17
)

# Library
add_library(PLACEHOLDER STATIC
  ${PROJECT_SOURCES}
)

# Library links
target_link_libraries(PLACEHOLDER 
  PRIVATE COMPILER_FEATURES
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
)

# Library includes
target_include_directories(PLACEHOLDER PUBLIC ${HEADERS_DIR})

# Static precompiler
target_precompile_headers(PLACEHOLDER PUBLIC ${HEADERS_DIR}/stdafx.h)

# Library Definitions
target_compile_definitions(PLACEHOLDER PRIVATE PLACEHOLDER_LIBRARY)