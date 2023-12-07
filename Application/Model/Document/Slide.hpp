#pragma once
#include "Shape/Shape.hpp"
#include "../Container.hpp"

class Slide : public Container, public IContainerItem {
public:
    std::string getInfo() const override;
};