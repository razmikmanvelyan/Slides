#include "Slide.hpp"

Slide::Slide() : _id(IdCounter++) {}

void Slide::addItem(std::shared_ptr<Item> item)
{
    _items.push_back(item);
}

auto Slide::getItems() -> Items&
{
    return _items;
}

void Slide::delItem(std::shared_ptr<Item> item)
{
    auto removeCondition = [ item ](std::shared_ptr<Item> elem) { return item == elem; };
    _items.erase(std::remove_if(_items.begin(), _items.end(), removeCondition), _items.end());
}

int Slide::getId() const
{
    return _id;
}


void Slide::setId(int id)
{
    _id = id;
}


std::shared_ptr<Item> Slide::getItemById(int id) const
{
    for (const auto& item : _items)
    {
        if (item->getId() == id)
        {
            return item;
        }
    }

    throw InvalidItemIdException("Invalid slide ID.");
}

int Slide::IdCounter = 1;
