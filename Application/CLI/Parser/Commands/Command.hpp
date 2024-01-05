#pragma once
#include <iostream>
#include <unordered_map>
#include "../../../Common/Exception/Exception.hpp"

using Arguments = std::unordered_map<std::string,std::string>;

class Command {
public:
    struct InvalidArgumentException : Exception { using Exception::Exception; };
    
public:
    Command(const Arguments& argumentsMap) : _argumentsMap(argumentsMap) {}
        
    virtual ~Command() {}

    virtual void exec() = 0;

protected:
    Arguments _argumentsMap; 
};