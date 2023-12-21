#pragma once

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class ShapeRectangle : public ShapeBase
{
public:
    ShapeRectangle() = default;
    std::shared_ptr<IShape> clone(std::shared_ptr<Item> item) const override;

public:
    void draw(QPainter&) override;
};