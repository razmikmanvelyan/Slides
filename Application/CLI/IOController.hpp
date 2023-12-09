#pragma once
#include <iostream>
#include <string>

class IOController{
public:
    IOController() : _inputStream(std::cin), _outputStream(std::cout) {}
public:
    std::string getLine() const;
    void writeLine(const std::string&);

private:
    std::istream& _inputStream;
    std::ostream& _outputStream;
};