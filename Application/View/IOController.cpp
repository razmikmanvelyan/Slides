#include "IOController.hpp"

std::string IOController::getLine() const {
    std::string line;
    std::getline(_inputStream, line);
    return line;
}
    
void IOController::writeLine( const std::string& line )
{
    _outputStream << line;
}
