#pragma once

#include <stdexcept>
#include "IContainer.hpp"

class Container : public IContainer {
public:
    ~Container();
public:
    void addItem(const std::shared_ptr<IContainerItem>&) override;
    void removeItem(int) override;
    std::shared_ptr<IContainerItem> getItem(int) const override;
    const std::vector<std::shared_ptr<IContainerItem>>& getItems() const override;
private:
    std::vector<std::shared_ptr<IContainerItem>> _items;
};