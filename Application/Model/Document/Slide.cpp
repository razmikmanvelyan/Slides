#include "Slide.hpp"

std::string Slide::getInfo() const {
    std::vector<std::shared_ptr<IContainerItem>> items = this->getItems();
    std::string result = "The Slide Contains " + std::to_string(items.size()) + " items \n     ";
    for(auto item : this->getItems()){
        result += item->getInfo();
    }
    return result;
}