#pragma once
#include "Command.hpp"

class NullCommand : public Command {
public:
    NullCommand() : Command({}) {}

public:
    void exec() override;
};