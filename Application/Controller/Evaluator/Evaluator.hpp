#pragma once
#include "Parser/Parser.hpp"
#include "Commands/CommandFactory.hpp"
class Evaluator {
public:
    Evaluator(std::shared_ptr<Document> document) : _document(document) {}
public:
    std::unique_ptr<Command> evaluate(const std::string&);
private:
    Tokenizer _tokenizer;
    Parser _parser;
    std::shared_ptr<Document> _document;
};