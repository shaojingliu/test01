#pragma once
#include "NtTerisBodyData.h"

class NtTerisBody
{
public:
    NtTerisBody(void);
    ~NtTerisBody(void);

    bool isDead() const;
    void initData(unsigned char* p);
    const NtTerisBodyData& getBodyData() const { return bodyData; }
    const NtPoint& getPosition() const { return position; }
    void setPosition(const NtPoint& pos) { position = pos; }
    void movePosition(const NtPoint& pos) { position.plus(pos); }
    NtPoint getSize() const ;
    void addData(const NtPoint& pos)  { bodyData.add(pos.x, pos.y); }
protected:
    NtTerisBodyData bodyData;
    NtPoint position;
};
