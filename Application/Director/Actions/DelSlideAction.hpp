#pragma once

#include "Action.hpp"
#include "../../App.hpp"
#include "../../Document/Document.hpp"

#include <memory>

class DelSlideAction : public Action
{
public:
    DelSlideAction(int slideId);
    
public:
    void exec() override;
    void revert() override;

private:
    int _slideId;
    std::shared_ptr<Slide> _deleted;
};
