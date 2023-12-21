#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include <any>
#include <tuple>
#include "AddCommand.hpp"
#include "UndoCommand.hpp"
#include "RedoCommand.hpp"
#include "ExitCommand.hpp"
#include "DelCommand.hpp"
#include "DisplayCommand.hpp"
#include "ListCommand.hpp"
#include "SaveCommand.hpp"
#include "LoadCommand.hpp"
#include "DrawCommand.hpp"

enum CommandType {
    ADD
};


class CommandRegistry{
public:
    static std::map<std::string, std::function<std::unique_ptr<Command>(std::vector<std::any>)>> commands;

public:
    static bool isCommand(std::string);
};
