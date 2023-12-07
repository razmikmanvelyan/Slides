#pragma once
#include <map>
#include <string>

enum CommandType {
    ADD
};


class CommandRegistry{
public:
    static std::map<std::string, CommandType> commands;

public:
    static bool isCommand(std::string);
};
