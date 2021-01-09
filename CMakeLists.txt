CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
PROJECT(Hippy.Flex VERSION 2021.0108 LANGUAGES CXX)

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

ADD_SUBDIRECTORY(Test/)