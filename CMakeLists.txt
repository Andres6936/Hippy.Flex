CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(Hippy.Flex VERSION 2021.0108 LANGUAGES CXX)

# The shared libraries are libraries that can be linked dynamically and loaded at runtime.
OPTION(HIPPY_FLEX_SHARED_LIBRARIES "Generate Shared Libraries" OFF)
OPTION(HIPPY_FLEX_BUILD_TESTS "Generate and Execute the Doryen Test" OFF)

# The OBJECT's can be used to compile the sources in the list given to add_library
# to object files, but then neither archiving them into a static library nor
# linking them into a shared object. The use of object libraries is
# particularly useful if one needs to create both static and shared libraries
# in one go.

# Property: OBJECT
ADD_LIBRARY(Hippy.Flex.Object
        Source/FlexLine.cpp
        Source/Hippy.cpp
        Source/HPLayoutCache.cpp
        Source/HPNode.cpp
        Source/HPStyle.cpp
        Source/HPUtil.cpp
        )
SET_TARGET_PROPERTIES(Hippy.Flex.Object PROPERTIES CXX_STANDARD 17)
TARGET_INCLUDE_DIRECTORIES(Hippy.Flex.Object PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>)

IF(HIPPY_FLEX_SHARED_LIBRARIES)

    # The POSITION_INDEPENDENT_CODE property determines whether position independent executables or
    # shared libraries will be created. This property is True by default for SHARED and MODULE library
    # targets and False otherwise.

    # Property: SHARED, POSITION_INDEPENDENT_CODE
    ADD_LIBRARY(Hippy.Flex SHARED $<TARGET_OBJECTS:Hippy.Flex.Object>)

ELSE()

    ADD_LIBRARY(Hippy.Flex STATIC $<TARGET_OBJECTS:Hippy.Flex.Object>)

ENDIF()

ADD_LIBRARY(Hippy::Flex ALIAS Hippy.Flex)
SET_TARGET_PROPERTIES(Hippy.Flex PROPERTIES CXX_STANDARD 17)
# It is necessary to repeat these instructions again, in case of not doing it, the executables
# will be unable to locate the Headers needed to perform the linking
TARGET_INCLUDE_DIRECTORIES(Hippy.Flex PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>)

IF(HIPPY_FLEX_BUILD_TESTS)

    # How do I use CTest? Simple: you first tell CMake to enable CTest by adding
    # the following line somewhere near the top of you main CMakeLists.txt
    # (usually right after the required cmake_minimum_required() and project())
    # Reference: https://bertvandenbroucke.netlify.app/2019/12/12/unit-testing-with-ctest/
    ENABLE_TESTING()

    ADD_SUBDIRECTORY(Test/)

ENDIF()