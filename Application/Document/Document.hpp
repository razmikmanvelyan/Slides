#pragma once

#include "Slide.hpp"
#include "../Common/Exception/Exception.hpp"

#include <vector>
#include <memory>

class Document
{
public:
    using Slides = std::vector<std::shared_ptr<Slide>>;

    struct InvalidSlideIdException : Exception { using Exception::Exception; };

public:
    void addSlide(std::shared_ptr<Slide>);
    void delSlide(std::shared_ptr<Slide>);
    std::shared_ptr<Slide> getSlideById(int) const;
    Slides& getSlides();

private:
    Slides _slides;
};