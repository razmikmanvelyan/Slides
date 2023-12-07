#include "AddCommand.hpp"

void AddCommand::exec() {
    if(!(this->validateArguments())){
        return;
    }
    auto it = _argumentsMap.find(TypeArg);
    if (it != _argumentsMap.end()) {
        if(it->second._value == "Slide"){
            _document->addItem(std::make_shared<Slide>());
        }
        if(it->second._value == "Shape"){
            auto slideId = _argumentsMap.find(SlideIDArg);
            if (it != _argumentsMap.end()) {
                std::shared_ptr<Slide> slide = std::dynamic_pointer_cast<Slide>(_document->getItem(std::stoi(slideId->second._value)));
                slide->addItem(ShapeFactory::create(_argumentsMap));
                std::cout << _document->getItem(std::stoi(slideId->second._value))->getInfo() << std::endl;
            }
        }
    } 
}

bool AddCommand::validateArguments(){
    for (const auto& entry : _argumentsMap) {
        if(!entry.second.isValid(AddCMDArgumentsRegistry())){
            std::cerr << "Error: Argument with name " << entry.second._name << " isn't valid" << std::endl;
            return false;
        }
    }
    return true;
}