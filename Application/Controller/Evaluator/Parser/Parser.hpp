#pragma once
#include <utility>
#include "../Tokenizer.hpp"
#include "../Commands/Command.hpp"
#include "../Commands/CommandRegistry.hpp"

class Parser {
public:
    std::pair<std::string, Arguments> parse(Tokens);
};