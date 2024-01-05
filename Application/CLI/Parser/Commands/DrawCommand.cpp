#include "DrawCommand.hpp"

DrawCommand::DrawCommand(const Arguments& arguments)
    : Command(arguments) {}

void DrawCommand::exec()
{

    try {
        auto id = std::stoi(_argumentsMap.at("-id"));
        auto document = App::getDocument();
        auto render = App::getRenderer();
        QImage image(200, 200, QImage::Format_RGB32);
        image.fill(Qt::white);
        render->draw(document->getSlideById(id), &image);
        try {
            auto filePath = _argumentsMap.at("-filePath");
            image.save(QString::fromStdString(filePath));
        }
        catch (std::logic_error e){
            throw InvalidArgumentException("The -filePath argument is undefined.");
        }
    }
    catch (std::logic_error e){
        throw InvalidArgumentException("The -id argument is undefined.");
    }
}
