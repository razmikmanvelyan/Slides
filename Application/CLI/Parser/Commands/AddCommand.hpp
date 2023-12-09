#pragma once

#include "Command.hpp"
#include "../../../Director/Director.hpp"
#include "../../../Director/Actions/AddItemAction.hpp"
#include "../../../Director/Actions/AddSlideAction.hpp"

class AddCommand : public Command{
public:
    AddCommand(const Arguments&);

    void exec() override;
};
