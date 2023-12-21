#include "CommandRegistry.hpp"

std::map<std::string, std::function<std::unique_ptr<Command>(std::vector<std::any>)>> CommandRegistry::commands = {
    {"ADD", [](std::vector<std::any> args) { 
        return std::make_unique<AddCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"UNDO", [](std::vector<std::any> args) { 
        return std::make_unique<UndoCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"REDO", [](std::vector<std::any> args) { 
        return std::make_unique<RedoCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"EXIT", [](std::vector<std::any> args) { 
        return std::make_unique<ExitCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"DEL", [](std::vector<std::any> args) { 
        return std::make_unique<DelCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"DISPLAY", [](std::vector<std::any> args) { 
        return std::make_unique<DisplayCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"LIST", [](std::vector<std::any> args) { 
        return std::make_unique<ListCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"SAVE", [](std::vector<std::any> args) { 
        return std::make_unique<SaveCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"LOAD", [](std::vector<std::any> args) { 
        return std::make_unique<LoadCommand>(std::any_cast<Arguments>(args[0])); 
    }},
    {"DRAW", [](std::vector<std::any> args) { 
        return std::make_unique<DrawCommand>(std::any_cast<Arguments>(args[0])); 
    }},
};

bool CommandRegistry::isCommand(std::string commandName){
    if(commands.count(commandName)> 0){
        return true;
    }
    return false;
}