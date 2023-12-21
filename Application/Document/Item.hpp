#pragma once
#include "../Common/Serialization/JsonSerializable.hpp"
#include <string>

class Item : public JsonSerializable
{
public:
    using Position = std::tuple<int, int, int, int>;
public:
    Item() = default;
    Item(const std::string& shape, const Position& pos, const std::string& color = "black");

public:
    std::string getShape() const;
    void setShape(const std::string&);

    std::string getColor() const;
    void setColor(const std::string&);

    Position getPosition() const;
    void setPosition(const Position&);

    int getId() const;

    QJsonObject toJson() const override;
    void fromJson(const QJsonObject&) override;


private:
    static int IdCounter;

    std::string _shape;
    std::string _color;
    Position _position;
    int _id;
};