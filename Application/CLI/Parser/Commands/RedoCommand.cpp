#include "RedoCommand.hpp"

RedoCommand::RedoCommand(const Arguments& arguments)
    : Command(arguments) {}

void RedoCommand::exec()
{
    App::getDirector()->redo();
}

