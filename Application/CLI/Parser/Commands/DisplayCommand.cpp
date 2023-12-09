#include "DisplayCommand.hpp"
#include "../../../Document/Document.hpp"
#include "../../../Rendering/Render.hpp"

DisplayCommand::DisplayCommand(const Arguments& argumentsMap)
    : Command(argumentsMap) {}

void DisplayCommand::exec()
{
    try {
        auto id = std::stoi(_argumentsMap.at("-id"));
        auto document = App::getDocument();
        auto render = App::getRenderer();

        render->print(document->getSlideById(id), std::cout);
    }
    catch (std::logic_error e){
        throw Exception("The -id argument is undefined.");
    }
}