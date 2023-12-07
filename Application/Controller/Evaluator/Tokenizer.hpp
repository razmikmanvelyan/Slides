#pragma once
#include <sstream>
#include <string>
#include <queue>

using Token = std::string;
using Tokens = std::queue<std::string>;


class Tokenizer{
public:
    Tokens getTokens(const std::string&);

private:
    char _separator = ' ';
};