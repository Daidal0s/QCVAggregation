# Target's variable
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/headers)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADERS_INLUDES ${HEADERS_DIR}/DataHandler.h)

# Source to compile
set(PROJECT_SOURCES
  ${SOURCE_DIR}/Hash.cpp
  ${SOURCE_DIR}/Seniority.cpp
)

# Library
add_library(AggregatorCore STATIC
  ${PROJECT_SOURCES}
)

configure_target(AggregatorCore)

# Library includes
target_include_directories(AggregatorCore PUBLIC ${HEADERS_DIR})

# Static precompiler
target_precompile_headers(AggregatorCore PUBLIC ${HEADERS_DIR}/stdafx.h)

# Library Definitions
target_compile_definitions(AggregatorCore 
  PRIVATE AggregatorCore_LIBRARY
)

