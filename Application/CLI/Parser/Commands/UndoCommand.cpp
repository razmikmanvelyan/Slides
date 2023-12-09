#include "UndoCommand.hpp"

UndoCommand::UndoCommand(const Arguments& arguments)
    : Command(arguments) {}

void UndoCommand::exec()
{
    App::getDirector()->undo();
}
