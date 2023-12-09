#pragma once

#include "IShape.hpp"
#include "ITextualDsiplayable.hpp"

#include <string>

class ShapeBase : public IShape, ITextualDisplayable
{
public:
    //std::unique_ptr<IShape> copy() const override;
    void print(std::ostream&) const override;

public:
    void setName(const std::string& name);
    void setColor(const std::string& color);

protected:
    std::string _name;
    std::string _color;
};