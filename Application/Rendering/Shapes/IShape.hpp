#pragma once
#include "../../Document/Item.hpp"
#include <memory>

class IShape
{
public:
    virtual ~IShape() {}
    virtual std::shared_ptr<IShape> clone(std::shared_ptr<Item>) const = 0;
};