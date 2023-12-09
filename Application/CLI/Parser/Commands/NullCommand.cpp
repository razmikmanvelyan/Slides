#include "NullCommand.hpp"

void NullCommand::exec() {
    throw Exception("Error: Invalid Command.");
}