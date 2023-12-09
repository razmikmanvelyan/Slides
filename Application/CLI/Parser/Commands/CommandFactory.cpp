#include "CommandFactory.hpp"

std::unique_ptr<Command> CommandFactory::create(const std::string& commandName, const Arguments& arguments) {
    
    auto it = CommandRegistry::commands.find(commandName);
    if (it != CommandRegistry::commands.end()) {
        return (it->second)({arguments});
    }
    return std::make_unique<NullCommand>();
}