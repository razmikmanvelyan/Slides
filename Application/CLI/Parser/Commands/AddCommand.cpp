#include "AddCommand.hpp"

AddCommand::AddCommand(const Arguments& argumentsMap)
    : Command(argumentsMap) {}

void AddCommand::exec() {
    auto typeIt = _argumentsMap.find("-type");
    if (typeIt == _argumentsMap.end()) {
        throw Exception("The -type argument is undefined.");
    }

    std::string type = typeIt->second;

    if (type == "slide") {
        auto slide = std::make_shared<Slide>();
        auto action = std::make_shared<AddSlideAction>(slide);
        App::getDirector()->exec(action);
    } else if (type == "item") {
        auto slideIdIt = _argumentsMap.find("-slide");
        auto shapeIt = _argumentsMap.find("-shape");
        auto colorIt = _argumentsMap.find("-color");
        auto ltIt = _argumentsMap.find("-lt");
        auto rbIt = _argumentsMap.find("-rb");

        if (slideIdIt == _argumentsMap.end() || shapeIt == _argumentsMap.end() ||
            colorIt == _argumentsMap.end() || ltIt == _argumentsMap.end() || rbIt == _argumentsMap.end()) {
            throw Exception("Arguments describing the Item are not defined.");
        }

        int slideId = std::stoi(slideIdIt->second);
        std::string shape = shapeIt->second;
        std::string color = colorIt->second;
        int lt = std::stoi(ltIt->second);
        int rb = std::stoi(rbIt->second);

        auto item = std::make_shared<Item>(shape, Item::Position{lt, rb}, color);
        auto action = std::make_shared<AddItemAction>(item, slideId);
        App::getDirector()->exec(action);
    } else {
        throw Exception("The value of the -type argument is incorrect.");
    }
}