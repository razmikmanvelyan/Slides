#include "DelItemAction.hpp"

DelItemAction::DelItemAction(int itemId, int slideId)
    : _itemId(itemId)
    , _slideId(slideId) {}
    
void DelItemAction::exec()
{
    deleted = App::getDocument()->getSlideById(_slideId)->getItemById(_itemId);
    App::getDocument()->getSlideById(_slideId)->delItem(deleted);
}

void DelItemAction::revert()
{
    App::getDocument()->getSlideById(_slideId)->delItem(deleted);
}
