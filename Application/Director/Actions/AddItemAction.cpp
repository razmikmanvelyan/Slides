#include "AddItemAction.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Item> item, int slideId)
    : _item(item)
    , _slideId(slideId) {}

void AddItemAction::exec()
{
    App::getDocument()->getSlideById(_slideId)->addItem(_item);
}

void AddItemAction::revert()
{
    App::getDocument()->getSlideById(_slideId)->delItem(_item);
}
