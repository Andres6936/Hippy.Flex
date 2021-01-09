ENABLE_TESTING()

INCLUDE(CMakeModules/CPM.cmake)

# Added Doctest as a Dependency
CPMADDPACKAGE(
        NAME DOCTEST
        GITHUB_REPOSITORY onqtam/doctest
        GIT_TAG 2.4.4
)

MACRO(HIPPY_FLEX_TEST_UNIT _NAME_TARGET _NAME_FILE)

    ADD_EXECUTABLE(${_NAME_TARGET} ${_NAME_FILE})
    SET_TARGET_PROPERTIES(${_NAME_TARGET} PROPERTIES CXX_STANDARD 17)
    TARGET_LINK_LIBRARIES(${_NAME_TARGET} PRIVATE doctest)
    TARGET_LINK_LIBRARIES(${_NAME_TARGET} PRIVATE Hippy::Flex)
    ADD_TEST(NAME ${_NAME_TARGET} COMMAND ${_NAME_TARGET})

ENDMACRO()

HIPPY_FLEX_TEST_UNIT(Hippy.Test.Absolute.Position HPAbsolutePositionTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Align.Content HPAlignContentTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Align.Items HPAlignItemsTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Align.Self HPAlignSelfTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Border HPBorderTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Computed.Margin HPComputedMarginTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Computed.Padding HPComputedPaddingTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Dimension HPDimensionTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Dirtied HPDirtiedTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Dirty.Marking HPDirtyMarkingTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Display HPDisplayTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Edge HPEdgeTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Flex.Direction HPFlexDirectionTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Flex HPFlexTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Flex.Wrap HPFlexWrapTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Had.Overflow HPHadOverflowTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Infinite.Height HPInfiniteHeightTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Justify.Content HPJustifyContentTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Margin HPMarginTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Measure.Cache HPMeasureCacheTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Measure.Mode HPMeasureModeTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Measure HPMeasureTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Min.Max.Dimension HPMinMaxDimensionTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Node.Child HPNodeChildTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Padding HPPaddingTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Relayout HPRelayoutTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Rounding.Measure.Func HPRoundingMeasureFuncTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Rounding HPRoundingTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Size.Overflow HPSizeOverflowTest.cpp)
HIPPY_FLEX_TEST_UNIT(Hippy.Test.Zero.Out.Layout.Recursively HPZeroOutLayoutRecursivelyTest.cpp)