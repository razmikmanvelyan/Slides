#pragma once
#include <utility>
#include "Tokenizer.hpp"
#include "Commands/Command.hpp"
#include "Commands/CommandRegistry.hpp"
#include "Commands/CommandFactory.hpp"
#include "../../Director/Director.hpp"

class Parser {
public:
    struct EmptyLineException : Exception { using Exception::Exception; };

public:
    std::unique_ptr<Command> parse(const std::string&);

private:
    Token getNext(Tokens&);
private:
    Tokenizer _tokenizer;
};