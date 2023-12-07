#include "NullCommand.hpp"

void NullCommand::exec() {
    return;
}

bool NullCommand::validateArguments(){
    return false;
}