#include "ShapeBase.hpp"

void ShapeBase::print(std::ostream& stream) const
{
    stream <<"Shape: name = " <<_name << ", _text = " << _text << ", color = " <<_color <<"\n";
}

void ShapeBase::setName(const std::string& name)
{
    _name = name;
}

void ShapeBase::setText(const std::string& text)
{
    _text = text;
}

void ShapeBase::setColor(const std::string& color)
{
    _color = color;
}

void ShapeBase::setBoundingBox(const BoundingBox& boundingBox)
{
    _boundingBox = boundingBox;
}
