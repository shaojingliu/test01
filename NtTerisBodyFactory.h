#pragma once
#include "NtTerisBody.h"

class NtTerisBodyFactory
{
public:
    NtTerisBodyFactory();
    ~NtTerisBodyFactory();

    static NtTerisBodyFactory& Get();
public:
    const NtTerisBody& CreateRandomBase();

protected:
    std::vector<NtTerisBody> baseBody;
};
