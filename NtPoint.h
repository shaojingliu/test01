#pragma once

struct NtPoint
{
    NtPoint(int _x, int _y) : x(_x), y(_y) {}
    NtPoint(): x(0), y(0) {}
    int x, y;

    void plus(const NtPoint& p)
    {
        x+= p.x;
        y+= p.y;
    }

    void dec(const NtPoint& p)
    {
        x-= p.x;
        y-= p.y;
    }

    void mul(const NtPoint& p)
    {
        x*= p.x;
        y*= p.y;
    }

    bool operator == ( const NtPoint& p) const
    {
        return x == p.x && y == p.y;
    }

    bool isValid() const;

    static NtPoint invalid;
};
