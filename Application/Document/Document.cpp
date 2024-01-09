#include "Document.hpp"

void Document::addSlide(std::shared_ptr<Slide> slide)
{
    _slides.push_back(slide);
}

auto Document::getSlides() -> Slides&
{
    return _slides;
}

std::shared_ptr<Slide> Document::getSlideById(int id) const
{
    for (const auto& slide : _slides)
    {
        if (slide->getId() == id)
        {
            return slide;
        }
    }

    throw InvalidSlideIdException("Invalid slide ID.");
}

void Document::delSlide(std::shared_ptr<Slide> slide)
{
    auto removeCondition = [ slide ](std::shared_ptr<Slide> elem) { return slide == elem; };
    _slides.erase(std::remove_if(_slides.begin(), _slides.end(), removeCondition), _slides.end());
}