#pragma once

#include "Command.hpp"
#include "../../../App.hpp"

class ExitCommand : public Command
{
public:
    ExitCommand(const Arguments&);
    void exec() override;
};