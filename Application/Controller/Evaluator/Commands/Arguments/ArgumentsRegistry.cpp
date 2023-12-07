#include "ArgumentsRegistry.hpp"

ArgumentsRegistry::ArgumentsRegistry(){
    std::map<std::string, ArgumentValueType> argumentsSyntax = {
    {TypeArg, ArgumentValueType::STRING},
    {SlideIDArg, ArgumentValueType::STRING},
    {WidthArg, ArgumentValueType::INT},
    {HeightArg, ArgumentValueType::INT},   
    {NameArg, ArgumentValueType::STRING},
    {ColorArg, ArgumentValueType::STRING},
    };
    _argumentsSyntax = argumentsSyntax;

}

std::map<std::string, ArgumentValueType>  ArgumentsRegistry::getArgumentsSyntax() const{
    return _argumentsSyntax;
}

std::map<std::string, std::vector<std::string>>  ArgumentsRegistry::getArgumentsSemantic() const{
    return _argumentsSemantic;
}

AddCMDArgumentsRegistry::AddCMDArgumentsRegistry() {

    std::map<std::string, std::vector<std::string>> argumentsSemantic = {
    {TypeArg,  {"Slide", "Shape"}},
    {WidthArg, {"13"}},
    };
    _argumentsSemantic = argumentsSemantic;
}
