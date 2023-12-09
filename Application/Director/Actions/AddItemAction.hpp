#pragma once

#include "Action.hpp"
#include "../../App.hpp"
#include "../../Document/Document.hpp"

#include <memory>

class AddItemAction : public Action
{
public:
    AddItemAction(std::shared_ptr<Item> item, int slideId);
    
public:
    void exec() override;
    void revert() override;

private:
    std::shared_ptr<Item> _item;
    int _slideId;
};