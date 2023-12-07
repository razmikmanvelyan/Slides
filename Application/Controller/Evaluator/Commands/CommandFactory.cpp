#include "CommandFactory.hpp"

std::unique_ptr< Command > CommandFactory::create(const std::string& commandName, const Arguments& arguments, std::shared_ptr<Document> document) {
    
    if (CommandRegistry::commands[commandName] == CommandType::ADD) {
        return std::make_unique< AddCommand >( arguments, document);
    }
    
    return std::make_unique< NullCommand >();

    /* if(auto iter = CommandRegistry::commands.find(commandName); iter != CommandRegistry::commands.end()) {
        return iter->second.clone(arguments);
    } */
}