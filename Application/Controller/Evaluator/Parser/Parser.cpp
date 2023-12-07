#include "Parser.hpp"

std::pair<std::string, Arguments> Parser::parse(Tokens tokens){
    std::pair<std::string, Arguments> result;
    if(CommandRegistry::isCommand(tokens.front())){
        result.first = tokens.front();
        tokens.pop();    
    }
    else{
        throw std::runtime_error("Command isn't valid");
    }
    Arguments args;
    while(tokens.size() > 0){
        std::string argumentName = tokens.front();
        tokens.pop();
        std::string argumentValue = tokens.front();
        tokens.pop();
        args.emplace(argumentName, Argument(argumentName, argumentValue));
    }
    result.second = args;
    return result;
}