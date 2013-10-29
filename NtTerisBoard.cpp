#include "stdafx.h"
#include "NtTerisBoard.h"
#include "NtTerisBodyFactory.h"

/*
------------------------------- 顶线
|                              初始化放置出生区 (8*8)
------------------------------- 警戒线, 超过此线OVER
|
|                              工件区
|
|
|
-------------------------------
*/

NtTerisBoard::NtTerisBoard(void)
{
}


NtTerisBoard::~NtTerisBoard(void)
{
}

void NtTerisBoard::createRandomScene()
{
    for(unsigned int i=0; i<2; ++i)
    {
        insertNewBody();
    }
}

bool NtTerisBoard::pushDown( const NtTerisBody& body )
{
    NtTerisBody lastBody = body;
    bool first = boardData.test(lastBody);
    if (!first)
    {
        return false;
    }

    while(1)
    {
        NtTerisBody downBody= lastBody;
        downBody.movePosition(NtPoint(0, 1));
        if (boardData.test(downBody))
        {
            lastBody = downBody;
        }
        else
        {
            boardData.place(lastBody);
            break;
        }
    }

    return true;
}

void NtTerisBoard::insertNewBody()
{
    NtTerisBody body = NtTerisBodyFactory::Get().CreateRandomBase();
    NtPoint sz = body.getSize();
    unsigned int x = rand() % (boardData.getWidth() - sz.x );
    body.movePosition(NtPoint(x, 0));
    pushDown(body);
}

boardDataType NtTerisBoard::at( const NtPoint& position )
{
    return boardData.at(position);
}

inline NtPoint getSingleStep(const NtPoint& direction)
{
    if (direction.x == 0 && direction.y == 0)
    {
        return NtPoint::invalid;
    }

    int x = abs(direction.x);
    int y = abs(direction.y);

    if (x>y)
    {
        return NtPoint(direction.x / x, 0);
    }

    return NtPoint(0, direction.y / y);
}

NtPoint NtTerisBoard::moveDirection( const NtPoint& position, const NtPoint& direction )
{
    boardDataType srcDt = boardData.at(position);
    if (!isBlockTeris(srcDt))
    {
        return NtPoint::invalid;
    }

    NtTerisBoardData copyBoard = boardData;
    NtTerisBody body = copyBoard.tackOut(srcDt);
    copyBoard.erase(srcDt);

    NtPoint advStep = getSingleStep(direction);
    if (advStep == NtPoint::invalid)
    {
        return advStep;
    }

    NtPoint target = advStep;
    target.x *= abs(direction.x);
    target.y *= abs(direction.y);

    wchar_t buff[256];
    wsprintf(buff, L"move dir: pos.x=%d, pos.y=%d\n", direction.x, direction.y);
    OutputDebugString(buff);

    NtPoint currStep;
    while(1)
    {
        body.setPosition(currStep);

        if (body.isOutside(NtPoint(BOARD_WIDTH, BOARD_HEIGHT)))
        {
            wchar_t buff[256];
            wsprintf(buff, L"pos.x=%d, pos.y=%d\n", currStep.x, currStep.y);
            OutputDebugString(buff);
            break;
        }

        if (copyBoard.test(body))
        {
            if (currStep == target)
            {
                boardData.erase(srcDt);
                boardData.place(body);
                break;
            }

            currStep.plus(advStep);
        }
        else
        {
            break;
        }
    }

    return currStep;
}

unsigned int NtTerisBoard::dispel()
{
    boardData.dispelAll();
    return 0;
}

