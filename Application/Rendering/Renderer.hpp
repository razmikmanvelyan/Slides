#pragma once

#include "../Document/Slide.hpp"
#include "Shapes/ShapeLib/ShapeLib.hpp"

#include <ostream>

class Renderer
{
public:
    void draw(std::shared_ptr<Slide>, QPaintDevice* device);
    void print(std::shared_ptr<Slide>, std::ostream& stream);
};