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
        placeData(ps, dt);
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
        boardDataType dt = at(ps);
        if (dt != BOARD_EMPTY)
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

void NtTerisBoardData::placeData( const NtPoint& p, boardDataType dt )
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

void NtTerisBoardData::erase( boardDataType dt )
{
    for(unsigned int r = 0; r<BOARD_HEIGHT; ++r)
    {
        for(unsigned int c =0; c<BOARD_WIDTH; ++c)
        {
            if (data[r][c] == dt)
            {
                data[r][c] = BOARD_EMPTY;
            }
        }
    }
}

NtTerisBody NtTerisBoardData::tackOut( boardDataType dt )
{
    NtTerisBody body;

    // step 1. find all and tack out
    if (!isBlockTeris(dt))
    {
        return body;
    }

    for( unsigned int r = 0; r< BOARD_HEIGHT; ++r)
    {
        for(unsigned int c =0; c< BOARD_WIDTH; ++c)
        {
            if(data[r][c]==dt)
            {
                body.addData(NtPoint(c, r));
            }
        }
    }
    return body;
}

void NtTerisBoardData::dispelAll()
{
    for( unsigned int r = 0; r< BOARD_HEIGHT; ++r)
    {
        if (canDispel(r))
        {
            eraseAndRelocate(r);
        }
    }
}

bool NtTerisBoardData::canDispel( int r )
{
    for(unsigned int i=0; i<BOARD_WIDTH; ++i)
    {
        if (!isBlockTeris(data[r][i]))
        {
            return false;
        }
    }
    return true;
}

void NtTerisBoardData::eraseAndRelocate( int row )
{
    for(unsigned int r=row; r>0; --r)
    {
        memcpy(&data[r][0], &data[r-1][0], sizeof(data[r]));
    }

    for(unsigned int c = 0; c < BOARD_WIDTH; ++c)
    {
        data[0][c] = BOARD_EMPTY;
    }
}

