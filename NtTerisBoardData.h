#pragma once 
#include "NtTerisBody.h"


typedef unsigned int boardDataType;

#define BOARD_INVALID (0xFFFFFFFF)
#define BOARD_EMPTY   (0x00000000)

inline bool isBlockTeris(boardDataType dt)
{
    return dt != BOARD_EMPTY && dt != BOARD_INVALID;
}

class NtTerisBoardData
{
public:
    NtTerisBoardData();
    bool inBoardBox(const NtPoint& position) const;
    bool test(const NtTerisBody& body);
    bool place(const NtTerisBody& body);
    boardDataType at(const NtPoint& p) const;
    unsigned int getWidth() const { return BOARD_WIDTH; }
    unsigned int getHeight() const { return BOARD_HEIGHT; }

protected:
    void placeEx(const NtPoint& p, boardDataType dt);

protected:
    boardDataType data[BOARD_HEIGHT][BOARD_WIDTH];
};
