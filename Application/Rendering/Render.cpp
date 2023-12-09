#include "Render.hpp"

void Render::draw(std::shared_ptr<Slide> slide)
{

}

void Render::print(std::shared_ptr<Slide> slide, std::ostream& stream)
{
    for (const auto& item : slide->getItems())
    {
        auto shape = ShapeLib::instance()->get(item->getShape());
        shape->print(stream);
    }
}
