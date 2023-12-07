#pragma once
#include <map>
#include <string>
#include <vector>

#define TypeArg  "-type"
#define SlideIDArg  "-SlideID"
#define WidthArg  "-width"
#define HeightArg  "-height"
#define NameArg  "-name"
#define ColorArg  "-color"

enum ArgumentValueType {
    INT,
    STRING
};

class ArgumentsRegistry {
protected:
    std::map<std::string, ArgumentValueType> _argumentsSyntax;
    std::map<std::string, std::vector<std::string>> _argumentsSemantic;

public:
    ArgumentsRegistry();
    virtual ~ArgumentsRegistry() {}
    std::map<std::string, ArgumentValueType> getArgumentsSyntax() const; 
    std::map<std::string, std::vector<std::string>> getArgumentsSemantic() const; 
};

class AddCMDArgumentsRegistry : public ArgumentsRegistry {
public:
    AddCMDArgumentsRegistry();
};
