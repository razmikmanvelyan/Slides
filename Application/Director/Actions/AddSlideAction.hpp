#pragma once

#include "Action.hpp"
#include "../../App.hpp"
#include "../../Document/Document.hpp"

class AddSlideAction : public Action
{
public:
    AddSlideAction(std::shared_ptr<Slide> slide);
    
public:
    void exec() override;
    void revert() override;

private:
    std::shared_ptr<Slide> _slide;
};