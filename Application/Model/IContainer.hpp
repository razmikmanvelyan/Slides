#pragma once
#include <memory>
#include <vector>
#include "IContainerItem.hpp"

class IContainer {
public:
    virtual void addItem(const std::shared_ptr<IContainerItem>& item) = 0;
    virtual void removeItem(int index) = 0;
    virtual std::shared_ptr<IContainerItem> getItem(int index) const = 0;
    virtual const std::vector<std::shared_ptr<IContainerItem>>& getItems() const = 0;
    virtual ~IContainer() {}
};