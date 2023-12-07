#include "Tokenizer.hpp"

Tokens Tokenizer::getTokens(const std::string& line){
    std::istringstream iss(line);

    Tokens tokens;
    for ( Token token; std::getline(iss, token, _separator); )
    {
        tokens.push(token);
    }
    return tokens;
}