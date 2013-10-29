#include "stdafx.h"
#include "NtTerisBody.h"

NtTerisBody::NtTerisBody(void)
{
}


NtTerisBody::~NtTerisBody(void)
{
}

bool NtTerisBody::isDead() const
{
    return bodyData.empty();
}

void NtTerisBody::initData( unsigned char* p )
{
    for(unsigned int r=0; r<8; ++r)
    {
        for(unsigned int c=0; c<8; ++c)
        {
            if (*p)
            {
                bodyData.add(c, r);
            }

            ++p;
        }
    }
}

NtPoint NtTerisBody::getSize() const
{
    NtPoint size;
    for(unsigned int i =0 ; i<bodyData.length(); ++i)
    {
        const NtPoint& p = bodyData.at(i);
        size.x = max(p.x, size.x);
        size.y = max(p.y, size.y);
    }
    return size;
}

bool NtTerisBody::isOutside(const NtPoint& sz) const
{
    for(unsigned int i =0 ; i<bodyData.length(); ++i)
    {
        NtPoint p = bodyData.at(i);
        p.plus(position);
        if (p.x < 0 || p.y < 0 || p.x >= sz.x || p.y >= sz.y)
        {
            return true;
        }
    }

    return false;
}

