#include "Evaluator.hpp"

std::unique_ptr<Command> Evaluator::evaluate(const std::string& line){
    Tokens tokens = _tokenizer.getTokens(line);
    std::pair<std::string, Arguments> cmdNameAndArgs = _parser.parse(tokens);
    std::unique_ptr cmd = CommandFactory::create(cmdNameAndArgs.first, cmdNameAndArgs.second, _document);
    return cmd;
}