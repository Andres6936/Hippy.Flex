CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(Hippy.Flex VERSION 2021.0108 LANGUAGES CXX)

# The shared libraries are libraries that can be linked dynamically and loaded at runtime.
OPTION(HIPPY_FLEX_SHARED_LIBRARIES "Generate Shared Libraries" OFF)
OPTION(HIPPY_FLEX_BUILD_TESTS "Generate and Execute the Doryen Test" OFF)

ADD_LIBRARY(Hippy.Flex
        Source/FlexLine.cpp
        Source/Hippy.cpp
        Source/HPLayoutCache.cpp
        Source/HPNode.cpp
        Source/HPStyle.cpp
        Source/HPUtil.cpp
        )
ADD_LIBRARY(Hippy::Flex ALIAS Hippy.Flex)
SET_TARGET_PROPERTIES(Hippy.Flex PROPERTIES CXX_STANDARD 17)
TARGET_INCLUDE_DIRECTORIES(Hippy.Flex PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>)

IF(HIPPY_FLEX_BUILD_TESTS)
    ADD_SUBDIRECTORY(Test/)
ENDIF()