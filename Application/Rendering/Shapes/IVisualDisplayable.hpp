#pragma once
#include <QPainter>

class IVisualDisplayable
{
public:
    virtual ~IVisualDisplayable() {}
    virtual void draw(QPainter&) = 0;
};