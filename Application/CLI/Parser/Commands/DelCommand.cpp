#include "DelCommand.hpp"
#include "../../../Director/Director.hpp"
#include "../../../Director/Actions/DelItemAction.hpp"
#include "../../../Director/Actions/DelSlideAction.hpp"

DelCommand::DelCommand(const Arguments& argumentsMap)
    : Command(argumentsMap) {}

void DelCommand::exec()
{
    try {
        auto slideId = std::stoi(_argumentsMap.at("-slideId"));
        try {
            auto itemId = std::stoi(_argumentsMap.at("-itemId"));
            App::getDirector()->exec(std::make_shared<DelItemAction>(itemId, slideId));
        }
        catch (std::logic_error e){
            App::getDirector()->exec(std::make_shared<DelSlideAction>(slideId));
        }
    }
    catch (std::logic_error e){
        throw InvalidArgumentException("Arguments invalid for Del command.");
    }   
}