#include "ListCommand.hpp"
#include "../../../Document/Document.hpp"

ListCommand::ListCommand(const Arguments& argumentsMap)
    : Command(argumentsMap) {}

void ListCommand::exec()
{
    std::cout <<"Slides:" <<std::endl;

    for (const auto& slide : App::getDocument()->getSlides())
    {
        std::cout <<slide->getId() <<std::endl;
    }
}