#include "Item.hpp"

Item::Item(const std::string& shape, const Position& pos, const std::string& color)
    : _shape(shape)
    , _position(pos)
    , _color(color)
    , _id(IdCounter++)
{}

std::string Item::getShape() const
{
    return _shape;
}

void Item::setShape(const std::string& shape)
{
    _shape = shape;
}

std::string Item::getColor() const
{
    return _color;
}

void Item::setColor(const std::string& color)
{
    _color = color;
}

auto Item::getPosition() const -> Position
{
    return _position;
}

void Item::setPosition(const Position& pos)
{
    _position = pos;
}

int Item::getId() const
{
    return _id;
}

int Item::IdCounter = 1;
