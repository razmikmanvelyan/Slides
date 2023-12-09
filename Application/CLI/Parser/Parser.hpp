#pragma once
#include <utility>
#include "Tokenizer.hpp"
#include "Commands/Command.hpp"
#include "Commands/CommandRegistry.hpp"
#include "Commands/CommandFactory.hpp"
#include "../../Director/Director.hpp"

class Parser {
public:
    std::unique_ptr<Command> parse(const std::string& line);

private:
    Token getNext(Tokens&);
private:
    Tokenizer _tokenizer;
    std::shared_ptr<Director> _director;
};