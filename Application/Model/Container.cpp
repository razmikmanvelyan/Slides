#include "Container.hpp"

Container::~Container(){
    _items.clear();
}

void Container::addItem(const std::shared_ptr<IContainerItem>& item) {
    _items.push_back(item);
}

void Container::removeItem(int index) {
    if(index < 0 || index >= _items.size()) {
        throw std::runtime_error("Item with this index doesn't exist");
    }
    _items.erase(_items.begin() + index);
}

std::shared_ptr<IContainerItem> Container::getItem(int index) const {
    if(index < 0 || index >= _items.size()) {
        throw std::runtime_error("Item with this index doesn't exist");
    }
    return _items[index];
}

const std::vector<std::shared_ptr<IContainerItem>>& Container::getItems() const {
    return _items;
}