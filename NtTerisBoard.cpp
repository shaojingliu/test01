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
    for(unsigned int i=0; i<3; ++i)
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

inline void amendBoardPosition(NtPoint& p)
{
    if ( p.x < 0 )
    {
        p.x = 0;
    } 
    else if (p.x >=BOARD_WIDTH)
    {
        p.x = BOARD_WIDTH-1;
    }

    if (p.y < 0 )
    {
        p.y = 0;
    }
    else if (p.y >= BOARD_HEIGHT)
    {
        p.y = BOARD_HEIGHT-1;
    }
}
