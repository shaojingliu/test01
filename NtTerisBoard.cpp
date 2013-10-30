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
    for(unsigned int i=0; i<10; ++i)
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

    NtPoint singleStep = getSingleStep(direction);
    if (singleStep == NtPoint::invalid)
    {
        return singleStep;
    }

    NtPoint targetStep = singleStep;
    targetStep.x *= abs(direction.x);
    targetStep.y *= abs(direction.y);

    NtPoint step;
	NtPoint lastStep;

    while(1)
    {
        body.setPosition(step);

        if (body.isOutside(NtPoint(BOARD_WIDTH, BOARD_HEIGHT)))
        {
            break;
        }

        if (copyBoard.test(body))
        {
            if (step == targetStep)
            {
				// succ.
                boardData.erase(srcDt);
                boardData.place(body);
                return step;
            }

			lastStep = step;
            step.plus(singleStep);
        }
        else
        {
            break;
        }
    }

	body.setPosition(lastStep);
	if (!body.isOutside(NtPoint(BOARD_WIDTH, BOARD_HEIGHT)))
	{
		if (copyBoard.test(body))
		{
			boardData.erase(srcDt);
			boardData.place(body);
			return lastStep;
		}
	}
    
	return NtPoint();
}

unsigned int NtTerisBoard::dispel()
{
    boardData.dispelAll();
    return 0;
}

void NtTerisBoard::updateGravity()
{
	for(int r = BOARD_HEIGHT-1; r >=0; --r)
	{
		for(unsigned int c = 0; c < BOARD_WIDTH; ++c)
		{
			moveDirection( NtPoint(c, r), NtPoint(0, BOARD_HEIGHT));
		}
	}
}
