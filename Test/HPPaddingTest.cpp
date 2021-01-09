/* Tencent is pleased to support the open source community by making Hippy available.
 * Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <Hippy/Flex/Hippy.h>

TEST(HippyTest, padding_no_size) {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetPadding(root, CSSLeft, 10);
  HPNodeStyleSetPadding(root, CSSTop, 10);
  HPNodeStyleSetPadding(root, CSSRight, 10);
  HPNodeStyleSetPadding(root, CSSBottom, 10);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(20, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(20, HPNodeLayoutGetHeight(root));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(20, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(20, HPNodeLayoutGetHeight(root));

  HPNodeFreeRecursive(root);

}

TEST(HippyTest, padding_container_match_child) {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetPadding(root, CSSLeft, 10);
  HPNodeStyleSetPadding(root, CSSTop, 10);
  HPNodeStyleSetPadding(root, CSSRight, 10);
  HPNodeStyleSetPadding(root, CSSBottom, 10);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetWidth(root_child0, 10);
  HPNodeStyleSetHeight(root_child0, 10);
  HPNodeInsertChild(root, root_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(30, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(30, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetHeight(root_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(30, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(30, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetHeight(root_child0));

  HPNodeFreeRecursive(root);

}

TEST(HippyTest, padding_flex_child) {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetPadding(root, CSSLeft, 10);
  HPNodeStyleSetPadding(root, CSSTop, 10);
  HPNodeStyleSetPadding(root, CSSRight, 10);
  HPNodeStyleSetPadding(root, CSSBottom, 10);
  HPNodeStyleSetWidth(root, 100);
  HPNodeStyleSetHeight(root, 100);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetFlexGrow(root_child0, 1);
  HPNodeStyleSetWidth(root_child0, 10);
  HPNodeInsertChild(root, root_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, HPNodeLayoutGetHeight(root_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(80, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, HPNodeLayoutGetHeight(root_child0));

  HPNodeFreeRecursive(root);

}

TEST(HippyTest, padding_stretch_child) {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetPadding(root, CSSLeft, 10);
  HPNodeStyleSetPadding(root, CSSTop, 10);
  HPNodeStyleSetPadding(root, CSSRight, 10);
  HPNodeStyleSetPadding(root, CSSBottom, 10);
  HPNodeStyleSetWidth(root, 100);
  HPNodeStyleSetHeight(root, 100);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetHeight(root_child0, 10);
  HPNodeInsertChild(root, root_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(80, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetHeight(root_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(80, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetHeight(root_child0));

  HPNodeFreeRecursive(root);

}

TEST(HippyTest, padding_center_child) {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetJustifyContent(root, FlexAlignCenter);
  HPNodeStyleSetAlignItems(root, FlexAlignCenter);
  HPNodeStyleSetPadding(root, CSSStart, 10);
  HPNodeStyleSetPadding(root, CSSEnd, 20);
  HPNodeStyleSetPadding(root, CSSBottom, 20);
  HPNodeStyleSetWidth(root, 100);
  HPNodeStyleSetHeight(root, 100);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetWidth(root_child0, 10);
  HPNodeStyleSetHeight(root_child0, 10);
  HPNodeInsertChild(root, root_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(40, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(35, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetHeight(root_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(50, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(35, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetHeight(root_child0));

  HPNodeFreeRecursive(root);

}

TEST(HippyTest, child_with_padding_align_end) {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetJustifyContent(root, FlexAlignEnd);
  HPNodeStyleSetAlignItems(root, FlexAlignEnd);
  HPNodeStyleSetWidth(root, 200);
  HPNodeStyleSetHeight(root, 200);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetPadding(root_child0, CSSLeft, 20);
  HPNodeStyleSetPadding(root_child0, CSSTop, 20);
  HPNodeStyleSetPadding(root_child0, CSSRight, 20);
  HPNodeStyleSetPadding(root_child0, CSSBottom, 20);
  HPNodeStyleSetWidth(root_child0, 100);
  HPNodeStyleSetHeight(root_child0, 100);
  HPNodeInsertChild(root, root_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(200, HPNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(200, HPNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root_child0));

  HPNodeFreeRecursive(root);

}
