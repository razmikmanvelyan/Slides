#include "ShapeLib.hpp"

std::shared_ptr<ShapeLib> ShapeLib::instance()
{
    static std::shared_ptr<ShapeLib> _instance;

    if (! _instance)
    {
        _instance = std::shared_ptr<ShapeLib>(new ShapeLib());
    }

    return _instance;
}

std::shared_ptr<ShapeBase> ShapeLib::get(std::shared_ptr<Item> item) 
{
    auto it = _shapes.find(item->getShape());
    if (it != _shapes.end()) 
    {
        return std::dynamic_pointer_cast<ShapeBase>(it->second->clone(item));
    }

    throw Exception("Invalid Shape name.");
}

ShapeLib::ShapeLib() {
    _shapes["Rectangle"] = std::make_unique<ShapeRectangle>();
}