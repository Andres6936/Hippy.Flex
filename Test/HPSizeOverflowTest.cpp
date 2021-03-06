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

TEST_CASE( "nested_overflowing_child") {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetWidth(root, 100);
  HPNodeStyleSetHeight(root, 100);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeInsertChild(root, root_child0, 0);

  const HPNodeRef root_child0_child0 = HPNodeNew();
  HPNodeStyleSetWidth(root_child0_child0, 200);
  HPNodeStyleSetHeight(root_child0_child0, 200);
  HPNodeInsertChild(root_child0, root_child0_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  CHECK_EQ(0, HPNodeLayoutGetLeft(root));
  CHECK_EQ(0, HPNodeLayoutGetTop(root));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetWidth(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  CHECK_EQ(0, HPNodeLayoutGetLeft(root));
  CHECK_EQ(0, HPNodeLayoutGetTop(root));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0));

  CHECK_EQ(-100, HPNodeLayoutGetLeft(root_child0_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetWidth(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0_child0));

  HPNodeFreeRecursive(root);

}

TEST_CASE( "nested_overflowing_child_in_constraint_parent") {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetWidth(root, 100);
  HPNodeStyleSetHeight(root, 100);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetWidth(root_child0, 100);
  HPNodeStyleSetHeight(root_child0, 100);
  HPNodeInsertChild(root, root_child0, 0);

  const HPNodeRef root_child0_child0 = HPNodeNew();
  HPNodeStyleSetWidth(root_child0_child0, 200);
  HPNodeStyleSetHeight(root_child0_child0, 200);
  HPNodeInsertChild(root_child0, root_child0_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  CHECK_EQ(0, HPNodeLayoutGetLeft(root));
  CHECK_EQ(0, HPNodeLayoutGetTop(root));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root_child0));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetWidth(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  CHECK_EQ(0, HPNodeLayoutGetLeft(root));
  CHECK_EQ(0, HPNodeLayoutGetTop(root));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root_child0));

  CHECK_EQ(-100, HPNodeLayoutGetLeft(root_child0_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetWidth(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0_child0));

  HPNodeFreeRecursive(root);

}

TEST_CASE( "parent_wrap_child_size_overflowing_parent") {

  const HPNodeRef root = HPNodeNew();
  HPNodeStyleSetWidth(root, 100);
  HPNodeStyleSetHeight(root, 100);

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetWidth(root_child0, 100);
  HPNodeInsertChild(root, root_child0, 0);

  const HPNodeRef root_child0_child0 = HPNodeNew();
  HPNodeStyleSetWidth(root_child0_child0, 100);
  HPNodeStyleSetHeight(root_child0_child0, 200);
  HPNodeInsertChild(root_child0, root_child0_child0, 0);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  CHECK_EQ(0, HPNodeLayoutGetLeft(root));
  CHECK_EQ(0, HPNodeLayoutGetTop(root));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0_child0));

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);

  CHECK_EQ(0, HPNodeLayoutGetLeft(root));
  CHECK_EQ(0, HPNodeLayoutGetTop(root));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root));
  CHECK_EQ(100, HPNodeLayoutGetHeight(root));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0));

  CHECK_EQ(0, HPNodeLayoutGetLeft(root_child0_child0));
  CHECK_EQ(0, HPNodeLayoutGetTop(root_child0_child0));
  CHECK_EQ(100, HPNodeLayoutGetWidth(root_child0_child0));
  CHECK_EQ(200, HPNodeLayoutGetHeight(root_child0_child0));

  HPNodeFreeRecursive(root);

}
