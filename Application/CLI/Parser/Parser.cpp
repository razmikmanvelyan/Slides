#include "Parser.hpp"

std::unique_ptr<Command> Parser::parse(const std::string& line){
    if (line.empty()) 
        throw Exception("Empty Line");

    Tokens tokens = _tokenizer.getTokens(line);
    Arguments args;
    std::string cmdName = getNext(tokens);
    while (! tokens.empty())
    {
        const Token argName = getNext(tokens); 
        const Token argValue = getNext(tokens); 
        args.emplace(argName, argValue);
    }
    return std::move(CommandFactory::create(cmdName, args));
}

Token Parser::getNext(Tokens& tokens){
    if (tokens.empty())
        throw Exception("Invalid argument");
    Token value = tokens.front();
    tokens.pop();
    return value;
}