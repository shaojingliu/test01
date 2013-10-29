#pragma once 
#include "NtTerisBody.h"

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
    void placeData(const NtPoint& p, boardDataType dt);
    void erase(boardDataType dt);
    NtTerisBody tackOut(boardDataType dt);
protected:
    boardDataType data[BOARD_HEIGHT][BOARD_WIDTH];
};
