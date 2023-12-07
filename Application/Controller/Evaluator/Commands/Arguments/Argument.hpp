#pragma once
#include <iostream>
#include <string>
#include "ArgumentsRegistry.hpp"

class Argument {
public:
    std::string _name;
    std::string _value;

public:
    bool isValid(const ArgumentsRegistry&) const;
private:
    bool isSyntaxValid(const ArgumentsRegistry&) const;
    bool isSemanticValid(const ArgumentsRegistry&) const;

};