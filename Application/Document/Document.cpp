#include "Document.hpp"

void Document::addSlide(std::shared_ptr<Slide> slide)
{
    _slides.push_back(slide);
}

auto Document::getSlides() const -> const Slides&
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

QJsonObject Document::toJson() const
{
    QJsonObject json;
    int index = 0;
    for (const auto& slide : _slides)
    {
        json[QString("slide%1").arg(index++)] = slide->toJson();
    }
    return json;
}

void Document::fromJson(const QJsonObject& jsonObject)
{
    _slides.clear();
    for (const auto& key : jsonObject.keys())
    {
        if (key.startsWith("slide"))
        {
            auto newSlide = std::make_shared< Slide >();
            newSlide->fromJson(jsonObject[key].toObject());
            _slides.push_back(newSlide);
        }
    }
}