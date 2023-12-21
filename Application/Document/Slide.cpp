#include "Slide.hpp"

Slide::Slide() : _id(IdCounter++) {}

void Slide::addItem(std::shared_ptr<Item> item)
{
    _items.push_back(item);
}

auto Slide::getItems() const -> const Items&
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


QJsonObject Slide::toJson() const 
{
    QJsonObject json;
    json["id"] = _id;
    int index = 0;
    for (const auto& item : _items) {
        json[QString("item%1").arg(index++)] = item->toJson();
    }
    return json;
}

void Slide::fromJson(const QJsonObject& jsonObject) 
{
    _items.clear();

    if (jsonObject.contains("id") && jsonObject["id"].isDouble())
    {
        _id = jsonObject["id"].toInt();
    }

    for (const auto& key : jsonObject.keys())
    {
        if (key.startsWith("item"))
        {
            auto newItem = std::make_shared< Item >();
            newItem->fromJson(jsonObject[key].toObject());
            _items.push_back(newItem);
        }
    }
}

int Slide::IdCounter = 1;
