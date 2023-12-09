#pragma once

#include "Command.hpp"
#include "../../../App.hpp"

class ListCommand : public Command
{
public:
    ListCommand(const Arguments&);
    void exec() override;
};