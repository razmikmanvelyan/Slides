#include "ExitCommand.hpp"

ExitCommand::ExitCommand(const Arguments& arguments)
    : Command(arguments) {}

void ExitCommand::exec()
{
    App::getController()->exit();
}

