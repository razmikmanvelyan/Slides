#pragma once

class IVisualDisplayable
{
public:
    virtual ~IVisualDisplayable() {}
    virtual void draw() = 0;
};