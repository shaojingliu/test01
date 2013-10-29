#include "stdafx.h"
#include "NtTerisBoardData.h"

bool NtTerisBoardData::place( const NtTerisBody& body )
{
    const NtPoint& position = body.getPosition();
    const NtTerisBodyData& bodyData= body.getBodyData();
    unsigned int len = bodyData.length();

    boardDataType dt = rand() % (0x7FFFFFFF-10) + 1;

    for(unsigned int i = 0; i<len; ++i)
    {
        NtPoint ps = bodyData.at(i);
        ps.plus(position);
        placeEx(ps, dt);
    }

    return true;
}

bool NtTerisBoardData::test( const NtTerisBody& body )
{
    const NtPoint& position = body.getPosition();
    const NtTerisBodyData& bodyData= body.getBodyData();
    unsigned int len = bodyData.length();
    for(unsigned int i = 0; i<len; ++i)
    {
        NtPoint ps = bodyData.at(i);
        ps.plus(position);
        if (at(ps) != BOARD_EMPTY)
        {
            return false;
        }
    }

    return true;
}

boardDataType NtTerisBoardData::at( const NtPoint& p ) const
{
    return (p.x < BOARD_WIDTH && p.y < BOARD_HEIGHT) ? data[p.y][p.x] : BOARD_INVALID;
}

void NtTerisBoardData::placeEx( const NtPoint& p, boardDataType dt )
{
    (p.x < BOARD_WIDTH && p.y < BOARD_HEIGHT) ? data[p.y][p.x] = dt : 0;
}

bool NtTerisBoardData::inBoardBox( const NtPoint& position ) const
{
    return position.x >= 0 && position.x < BOARD_WIDTH &&
        position.y >= 0 && position.y < BOARD_HEIGHT;
}

NtTerisBoardData::NtTerisBoardData()
{
    memset(data, 0, sizeof(data));
}
