#include "stdafx.h"
#include "NtTerisBodyFactory.h"

unsigned char sharp1[64] = 
{
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

unsigned char sharp2[64] = 
{
    0, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

unsigned char sharp3[64] = 
{
    0, 1, 1, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

unsigned char sharp4[64] = 
{
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

unsigned char sharp5[64] = 
{
    1, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

unsigned char sharp6[64] = 
{
    0, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

NtTerisBodyFactory& NtTerisBodyFactory::Get()
{
    static NtTerisBodyFactory factory;
    return factory;
}

const NtTerisBody& NtTerisBodyFactory::CreateRandomBase()
{
    //unsigned int index = rand() % ( baseBody.size() );
    //return baseBody[index];
    return baseBody[4];
}

NtTerisBodyFactory::NtTerisBodyFactory()
{
    {
        NtTerisBody body;
        body.initData(sharp1);
        baseBody.push_back(body);
    }

    {
        NtTerisBody body;
        body.initData(sharp2);
        baseBody.push_back(body);

    }
    {

        NtTerisBody body;
        body.initData(sharp3);
        baseBody.push_back(body);

    }
    {
        NtTerisBody body;
        body.initData(sharp4);
        baseBody.push_back(body);
    }
    {
        NtTerisBody body;
        body.initData(sharp5);
        baseBody.push_back(body);
    }
    {
        NtTerisBody body;
        body.initData(sharp6);
        baseBody.push_back(body);
    }
}


NtTerisBodyFactory::~NtTerisBodyFactory()
{

}

