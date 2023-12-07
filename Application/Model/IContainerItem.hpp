#pragma once
#include <string>

class IContainerItem {
public:
    virtual std::string getInfo() const = 0;
    virtual ~IContainerItem() {}
};