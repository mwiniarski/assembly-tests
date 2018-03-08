project(SampleProject_Tests)

add_executable(sample_test HashmapBuilderTests.cpp)

target_link_libraries(sample_test gtest gtest_main)
target_link_libraries(sample_test src)