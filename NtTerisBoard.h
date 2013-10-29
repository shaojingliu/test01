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

protected:
    NtTerisBoardData boardData;
    std::vector<NtTerisBody> bodys;
};
