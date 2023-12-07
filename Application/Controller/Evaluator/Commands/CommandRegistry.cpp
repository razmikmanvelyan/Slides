#include "CommandRegistry.hpp"

std::map<std::string, CommandType> CommandRegistry::commands = {
    {"ADD", CommandType::ADD}
};

bool CommandRegistry::isCommand(std::string commandName){
    if(commands.count(commandName) > 0){
        return true;
    }
    return false;
}