#pragma once

#include "IShape.hpp"
#include "ITextualDsiplayable.hpp"
#include "IVisualDisplayable.hpp"

#include <string>

class ShapeBase : public IShape, ITextualDisplayable, IVisualDisplayable
{
public:
    using BoundingBox = std::tuple<int, int, int, int>;
public:
    virtual std::shared_ptr<IShape> clone(std::shared_ptr<Item>) const override = 0;
    virtual void draw(QPainter&) override = 0;
    void print(std::ostream&) const override;

public:
    void setName(const std::string&);
    void setColor(const std::string&);
    void setText(const std::string&);
    void setBoundingBox(const BoundingBox&);

protected:
    std::string _name;
    std::string _color;
    std::string _text;
    BoundingBox _boundingBox;
};