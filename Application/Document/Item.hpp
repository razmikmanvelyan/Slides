#pragma once

#include <string>

class Item
{
public:
    using Position = std::pair<int, int>;
public:
    Item(const std::string& shape, const Position& pos, const std::string& color = "black");

public:
    std::string getShape() const;
    void setShape(const std::string&);

    std::string getColor() const;
    void setColor(const std::string&);

    Position getPosition() const;
    void setPosition(const Position& pos);

    int getId() const;
    
private:
    static int IdCounter;

    std::string _shape;
    std::string _color;
    Position _position;
    const int _id;
};