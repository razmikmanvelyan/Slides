#pragma once

#include "Item.hpp"
#include "../Common/Exception/Exception.hpp"

#include <vector>
#include <memory>
#include <algorithm>

class Slide
{
public:
    using Items = std::vector<std::shared_ptr<Item>>;

    struct InvalidItemIdException : Exception { using Exception::Exception; };

public:
    Slide();

public:
    void addItem(std::shared_ptr<Item>);
    void delItem(std::shared_ptr<Item>);
    std::shared_ptr<Item> getItemById(int) const;
    Items& getItems();
    int getId() const;
    void setId(int);

private:
    static int IdCounter;
    Items _items;
    int _id;
};