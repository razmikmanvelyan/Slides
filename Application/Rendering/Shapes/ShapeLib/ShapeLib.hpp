#pragma once

#include "../ShapeBase.hpp"
#include "../ShapeRectangle.hpp"
#include "../../../Common/Exception/Exception.hpp"

#include <memory>
#include <unordered_map>

class ShapeLib 
{
public:
    // struct InvalidShapeException : Exception { using Exception::Exception; };

public:
    static std::shared_ptr<ShapeLib> instance();

    std::shared_ptr<ShapeBase> get(const std::string& shape);

private:
    ShapeLib();
    std::unordered_map<std::string, std::shared_ptr<ShapeBase>> _shapes;
};