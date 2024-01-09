#include "Item.hpp"

Item::Item(const std::string& shape, const Position& pos, const std::string& color, const std::string& text)
    : _shape(shape)
    , _position(pos)
    , _color(color)
    , _text(text)
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

std::string Item::getText() const
{
    return _text;
}

void Item::setText(const std::string& text)
{
    _text = text;
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

void Item::setId(int id)
{
    _id = id;
}

int Item::IdCounter = 1;
