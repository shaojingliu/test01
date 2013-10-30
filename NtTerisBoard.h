#pragma once
#include "NtConfig.h"
#include "NtTerisBody.h"
#include "NtTerisBoardData.h"

class NtTerisBoard
{
public:
    NtTerisBoard(void);
    ~NtTerisBoard(void);

    void createRandomScene();
    bool pushDown(const NtTerisBody& body);
    const NtTerisBoardData& getBoardData() const { return boardData; }
    void insertNewBody();
    boardDataType at(const NtPoint& position);
    NtPoint moveDirection(const NtPoint& position, const NtPoint& direction);
	void updateGravity();
    unsigned int dispel();

protected:
    NtTerisBoardData boardData;
};
