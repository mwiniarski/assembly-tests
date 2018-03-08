project(SampleProject)

set(SOURCE_FILES
        HashmapBuilder.cpp HashmapBuilder.h FileLoader.cpp FileLoader.h)

add_library(src STATIC ${SOURCE_FILES})