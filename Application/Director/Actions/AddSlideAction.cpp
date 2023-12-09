#include "AddSlideAction.hpp"

AddSlideAction::AddSlideAction(std::shared_ptr<Slide> slide)
    : _slide(slide) {}

void AddSlideAction::exec()
{
    App::getDocument()->addSlide(_slide);
}

void AddSlideAction::revert()
{
    App::getDocument()->delSlide(_slide);
}
