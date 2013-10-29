#include "stdafx.h"
#include "NtTerisBodyData.h"

NtTerisBodyData::NtTerisBodyData() 
: len(0)
{
}

NtTerisBodyData::~NtTerisBodyData()
{

}

bool NtTerisBodyData::empty() const
{
    return len == 0;
}

bool NtTerisBodyData::add( unsigned int x, unsigned int y )
{
    if (len >= ARRAY_COUNT(pos))
    {
        return false;
    }

    pos[len].x = x;
    pos[len].y = y;

    ++len;

    return true;
}

bool NtTerisBodyData::remove( unsigned int x, unsigned int y )
{
    for(unsigned int i=0; i<len; ++i)
    {
        if (pos[i].x == x && pos[i].y == y)
        {
            return removeAt(i);
        }
    }

    return false;
}

bool NtTerisBodyData::removeAt( unsigned int index )
{
    if (index < len && len > 0)
    {
        if (index != len-1)
        {
            pos[index] = pos[len-1];
        }
        --len;

        return true;
    }

    return false;
}

const NtPoint& NtTerisBodyData::at( unsigned int index ) const
{
    if (index < len)
    {
        return pos[index];
    }

    return NtPoint::invalid;
}
