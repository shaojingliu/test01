#pragma once


class NtTerisBodyData
{
public:
    NtTerisBodyData();
    ~NtTerisBodyData();

    bool empty() const;
    bool add(unsigned int x, unsigned int y);
    bool remove(unsigned int x, unsigned int y);
    bool removeAt(unsigned int index);
    const NtPoint& at(unsigned int index) const;
    unsigned int length() const { return len; }
protected:
    NtPoint pos[16];
    unsigned int len;
};
