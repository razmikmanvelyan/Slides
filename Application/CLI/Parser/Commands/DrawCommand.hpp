#pragma once
#include "../../../App.hpp"
class DrawCommand : public Command
{
public:
    DrawCommand(const Arguments&);
    void exec() override;
};