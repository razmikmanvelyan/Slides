#pragma once

#include <variant>
#include <map>

class Action
{
public:
    virtual ~Action() {}

public:
    virtual void exec() = 0;
    virtual void revert() = 0;
};