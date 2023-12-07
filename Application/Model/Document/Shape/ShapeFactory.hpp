#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include "../../../Controller/Evaluator/Commands/Arguments/Argument.hpp"
#include "Rectangle.hpp"

class ShapeFactory
{
    using Arguments = std::unordered_map<std::string, Argument>;

public:
    static std::unique_ptr< Shape > create( const Arguments& );
};