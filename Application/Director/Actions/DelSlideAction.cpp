#include "DelSlideAction.hpp"

DelSlideAction::DelSlideAction(int slideId)
    : _slideId(slideId) {}
    
void DelSlideAction::exec()
{
    _deleted = App::getDocument()->getSlideById(_slideId);
    App::getDocument()->delSlide(_deleted);
}

void DelSlideAction::revert()
{
    App::getDocument()->addSlide(_deleted);
}
