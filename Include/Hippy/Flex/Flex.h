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

#ifndef FLEX_H_
#define FLEX_H_

typedef enum {
  DirectionInherit,
  DirectionLTR,
  DirectionRTL
} HPDirection;

/**
 * Flex Direction : row | row-reverse | column | column-reverse
 * <br><br>
 *
 * The flex-direction property specifies how flex items are placed in the flex
 * container, by setting the direction of the flex container’s main axis. This
 * determines the direction in which flex items are laid out. <br><br>
 *
 * - Row: The flex container’s main axis has the same orientation as the inline
 * 	axis of the current writing mode. The main-start and main-end directions are
 * 	equivalent to the inline-start and inline-end directions, respectively, of
 * 	the current writing mode. <br><br>
 *
 * - Row Reverse: Same as row, except the main-start and main-end directions are
 * 	swapped. <br><br>
 *
 * - Column: The flex container’s main axis has the same orientation as the
 * 	block axis of the current writing mode. The main-start and main-end
 * 	directions are equivalent to the block-start and block-end directions,
 * 	respectively, of the current writing mode. <br><br>
 *
 * - Column Reverse: Same as column, except the main-start and main-end
 * 	directions are swapped. <br><br>
 */
typedef enum {
  FLexDirectionRow,
  FLexDirectionRowReverse,
  FLexDirectionColumn,
  FLexDirectionColumnReverse
} FlexDirection;

//flex-wrap: nowrap | wrap | wrap-reverse
typedef enum {
  FlexNoWrap,
  FlexWrap,
  FlexWrapReverse,
} FlexWrapMode;

//align-item: flex-start | flex-end | center | baseline | stretch
//align-self:	auto | flex-start | flex-end | center | baseline | stretch
//justify-content: flex-start | flex-end | center | space-between | space-around | space-evenly

typedef enum {
  FlexAlignAuto,
  FlexAlignStart,
  FlexAlignCenter,
  FlexAlignEnd,
  FlexAlignStretch,
  FlexAlignBaseline,
  FlexAlignSpaceBetween,
  FlexAlignSpaceAround,
  FlexAlignSpaceEvenly
} FlexAlign;

//layout size value
typedef struct HPSize {
  float width;
  float height;
} HPSize;

//used to get padding's margin and position in main axis or cross axis
typedef enum {
  CSSLeft = 0,
  CSSTop,
  CSSRight,
  CSSBottom,
  CSSStart,
  CSSEnd,
  CSSHorizontal,
  CSSVertical,
  CSSAll,
  CSSNONE = -1
} CSSDirection;

typedef enum {
  DimWidth = 0,
  DimHeight,
} Dimension;

typedef enum {
  PositionTypeRelative,
  PositionTypeAbsolute,
} PositionType;

typedef enum {
  DisplayTypeFlex,
  DisplayTypeNone,
} DisplayType;

typedef enum {
  OverflowVisible,
  OverflowHidden,
  OverflowScroll,
} OverflowType;

typedef enum {
  NodeTypeDefault,
  NodeTypeText
} NodeType;

typedef struct {
  float position[4];
  float cachedPosition[4];
  float dim[2];
  float margin[4];
  float padding[4];
  float border[4];
  bool hadOverflow;
  HPDirection direction;
  //used to layout
  float flexBaseSize;
  float hypotheticalMainAxisMarginBoxSize;
  float hypotheticalMainAxisSize;
} HPLayout;

typedef enum {
  LayoutActionMeasureWidth = 1,
  LayoutActionMeasureHeight = 2,
  LayoutActionLayout = 3,
} FlexLayoutAction;

typedef enum {
  MeasureModeUndefined,
  MeasureModeExactly,
  MeasureModeAtMost,
} MeasureMode;

typedef struct {
  MeasureMode widthMeasureMode;
  MeasureMode heightMeasureMode;
} HPSizeMode;


//following arrays mapping with axis's direction
const CSSDirection axisStart[4] = { CSSLeft, CSSRight, CSSTop, CSSBottom };
const CSSDirection axisEnd[4] = { CSSRight, CSSLeft, CSSBottom, CSSTop };
const Dimension axisDim[4] = { DimWidth, DimWidth, DimHeight, DimHeight };

bool inline isRowDirection(FlexDirection dir) {
  return dir == FLexDirectionRow || dir == FLexDirectionRowReverse;
}

bool inline isColumnDirection(FlexDirection dir) {
  return dir == FLexDirectionColumn || dir == FLexDirectionColumnReverse;
}

bool inline isReverseDirection(FlexDirection dir) {
  return dir == FLexDirectionColumnReverse || dir == FLexDirectionRowReverse;
}

#endif
