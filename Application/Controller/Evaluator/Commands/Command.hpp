#pragma once
#include <iostream>
#include <unordered_map>
#include "Arguments/Argument.hpp"

using Arguments = std::unordered_map<std::string,Argument>;

class Command {
public:
    Command( const Arguments& argumentsMap ) : _argumentsMap(argumentsMap) {}
        
    virtual ~Command() {}

    virtual void exec() = 0;

protected:
    virtual bool validateArguments() = 0;

protected:
    Arguments _argumentsMap; 
};