#pragma once

#include "Command.hpp"
#include "../../../App.hpp"

class DisplayCommand : public Command
{
public:
    DisplayCommand(const Arguments&);
    void exec() override;
};
