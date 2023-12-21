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
        auto lt_xIt = _argumentsMap.find("-lt_x");
        auto lt_yIt = _argumentsMap.find("-lt_y");
        auto rb_xIt = _argumentsMap.find("-rb_x");
        auto rb_yIt = _argumentsMap.find("-rb_y");

        if (slideIdIt == _argumentsMap.end() || shapeIt == _argumentsMap.end() ||
            colorIt == _argumentsMap.end() || lt_xIt == _argumentsMap.end() || lt_yIt == _argumentsMap.end() || rb_xIt == _argumentsMap.end() || rb_yIt == _argumentsMap.end()) {
            throw Exception("Arguments describing the Item are not defined.");
        }

        int slideId = std::stoi(slideIdIt->second);
        std::string shape = shapeIt->second;
        std::string color = colorIt->second;
        int lt_x = std::stoi(lt_xIt->second);
        int lt_y = std::stoi(lt_yIt->second);
        int rb_x = std::stoi(rb_xIt->second);
        int rb_y = std::stoi(rb_yIt->second);

        auto item = std::make_shared<Item>(shape, Item::Position{lt_x, lt_y, rb_x, rb_y}, color);
        auto action = std::make_shared<AddItemAction>(item, slideId);
        App::getDirector()->exec(action);
    } else {
        throw Exception("The value of the -type argument is incorrect.");
    }
}