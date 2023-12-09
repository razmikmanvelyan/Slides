#pragma once

#include <ostream>

class ITextualDisplayable
{
public:
    virtual ~ITextualDisplayable() {}
    virtual void print(std::ostream&) const = 0;
};
