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


QJsonObject Item::toJson() const {
    QJsonObject json;
    json["id"] = _id;
    json["shape"] = QString::fromStdString(_shape);
    json["color"] = QString::fromStdString(_color);
    json["text"] = QString::fromStdString(_text);
    json["tl_x"] = std::get<0>(_position);
    json["tl_y"] = std::get<1>(_position);
    json["rb_x"] = std::get<2>(_position);
    json["rb_y"] = std::get<3>(_position);
    return json;  
}

void Item::fromJson(const QJsonObject& jsonObject) {
    if (jsonObject.contains("id") && jsonObject["id"].isDouble())
    {
        _id = jsonObject["id"].toInt();
    }

    if (jsonObject.contains("shape") && jsonObject["shape"].isString())
    {
        _shape = jsonObject["shape"].toString().toStdString();
    }

    if (jsonObject.contains("color") && jsonObject["color"].isString())
    {
        _color = jsonObject["color"].toString().toStdString();
    }

    if (jsonObject.contains("text") && jsonObject["text"].isString())
    {
        _text = jsonObject["text"].toString().toStdString();
    }
    if (jsonObject.contains("tl_x") && jsonObject["tl_x"].isDouble()
        && jsonObject.contains("tl_y") && jsonObject["tl_y"].isDouble()
        && jsonObject.contains("rb_x") && jsonObject["rb_x"].isDouble()
        && jsonObject.contains("rb_y") && jsonObject["rb_y"].isDouble())
    {
        _position = std::make_tuple(jsonObject["tl_x"].toInt(), jsonObject["tl_y"].toInt(), jsonObject["rb_x"].toInt(), jsonObject["rb_y"].toInt());
    }
}

int Item::IdCounter = 1;
