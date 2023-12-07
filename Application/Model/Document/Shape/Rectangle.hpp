#pragma once
#include "Shape.hpp"

class Rectangle : public Shape{
public:
    std::string getInfo() const override {
        std::string result = " Shape Info: Name = Rectangle, Color = " + this->getColor() + ", \n     ";
        return result;
    }
};