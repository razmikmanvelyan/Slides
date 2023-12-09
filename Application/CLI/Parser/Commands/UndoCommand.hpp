#pragma once

#include "Command.hpp"
#include "../../../App.hpp"

class UndoCommand : public Command
{
public:
    UndoCommand(const Arguments&);
    void exec() override;
};