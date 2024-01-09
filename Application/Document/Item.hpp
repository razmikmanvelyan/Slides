#pragma once
#include <string>

class Item
{
public:
    using Position = std::tuple<int, int, int, int>;
public:
    Item() = default;
    Item(const std::string& shape, const Position& pos, const std::string& color = "black", const std::string& text = "");

public:
    std::string getShape() const;
    void setShape(const std::string&);

    std::string getColor() const;
    void setColor(const std::string&);

    std::string getText() const;
    void setText(const std::string&);

    Position getPosition() const;
    void setPosition(const Position&);

    int getId() const;
    void setId(int);

private:
    static int IdCounter;

    std::string _shape;
    std::string _color;
    std::string _text;
    Position _position;
    int _id;
};