#pragma once

#include <vector>
#include <algorithm>

// 获得数组个数
#define ARRAY_COUNT(a)  ( sizeof(a)/sizeof((a)[0]) )

// 宽度
#define BOARD_WIDTH 20
// 高度
#define BOARD_HEIGHT 40

typedef unsigned int boardDataType;

#define BOARD_INVALID (0xFFFFFFFF)

#define BOARD_EMPTY   (0x00000000)

inline bool isBlockTeris(boardDataType dt)
{
    return dt != BOARD_EMPTY && dt != BOARD_INVALID;
}
