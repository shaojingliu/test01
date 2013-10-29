#include "stdafx.h"

NtPoint NtPoint::invalid(0x7FFFFFFF, 0x7FFFFFFF);

bool NtPoint::isValid() const
{
    return *this == invalid;
}
