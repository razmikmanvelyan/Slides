#pragma once

#include "Command.hpp"
#include "../../../App.hpp"

class DelCommand : public Command
{
public:
    DelCommand(const Arguments&);
    void exec() override;
};