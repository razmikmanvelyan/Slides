#pragma once
#include "../../IContainerItem.hpp"

class Shape : public IContainerItem {
public:
    Shape() {}
    virtual ~Shape() {}

public:
    std::string getColor() const {
        return _color;
    }

    void setColor(const std::string& color) {
        _color = color;
    }

private:
    std::string _color;
};