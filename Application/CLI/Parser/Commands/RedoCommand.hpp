#pragma once
#include "Command.hpp"
#include "../../../App.hpp"

class RedoCommand : public Command
{
public:
    RedoCommand(const Arguments&);
    void exec() override;
};