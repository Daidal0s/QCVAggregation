add_executable(coreTest test.cpp)
target_link_libraries(coreTest PRIVATE AggregatorCore)
configure_target(coreTest)
configure_test(coreTest)
