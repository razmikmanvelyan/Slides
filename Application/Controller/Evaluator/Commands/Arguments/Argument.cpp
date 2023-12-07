#include "Argument.hpp"
#include "../../../../../Utilities/HelperUtility.hpp"

bool Argument::isSyntaxValid(const ArgumentsRegistry& argumentsRegistry) const {
    if (argumentsRegistry.getArgumentsSyntax().count(_name) > 0) {
        switch (argumentsRegistry.getArgumentsSyntax()[_name]) {
            case ArgumentValueType::INT :
                try {
                    int t = std::stoi(_value);
                    return true;
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid argument error: " << e.what() << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << "Out of range error: " << e.what() << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
                }
                return false;
                break;
            case ArgumentValueType::STRING :
                return true;
                break;
            default:
                break;
        }
    }
    return false;
}

bool Argument::isSemanticValid(const ArgumentsRegistry& argumentsRegistry) const {
    auto _argumentsSemantic = argumentsRegistry.getArgumentsSemantic();
    if (_argumentsSemantic.count(_name) > 0) {
        if(_argumentsSemantic[_name].size() == 0){
            return true;
        }
        if(std::find(_argumentsSemantic[_name].begin(), _argumentsSemantic[_name].end(), _value)  
                != _argumentsSemantic[_name].end()) {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}

bool Argument::isValid(const ArgumentsRegistry& argumentsRegistry) const {
    return isSyntaxValid(argumentsRegistry) && isSemanticValid(argumentsRegistry);
}