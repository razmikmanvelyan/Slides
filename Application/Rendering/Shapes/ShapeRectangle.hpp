#pragma once

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class ShapeRectangle : public ShapeBase, public IVisualDisplayable
{
public:
    ShapeRectangle() = default;

public:
    void draw() override;
};