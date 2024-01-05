#include "Renderer.hpp"

void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* device)
{
    QPainter painter(device);
    for (const auto& item : slide->getItems())
    {
        auto shape = ShapeLib::instance()->get(item);
        shape->draw(painter);
    }
}

void Renderer::print(std::shared_ptr<Slide> slide, std::ostream& stream)
{
    for (const auto& item : slide->getItems())
    {
        auto shape = ShapeLib::instance()->get(item);
        shape->print(stream);
    }
}
