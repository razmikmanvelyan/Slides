#pragma once
#include <iostream>
#include <string>

class IOController{
public:
    IOController( std::istream& inputStream, std::ostream& outputStream) : _inputStream(inputStream), _outputStream(outputStream) {}
public:
    std::string getLine() const;
    void writeLine( const std::string& );

private:
    std::istream& _inputStream;
    std::ostream& _outputStream;
};