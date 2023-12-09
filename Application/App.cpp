#include "App.hpp"

std::shared_ptr<ControllerBase> App::_controller;
std::shared_ptr<Document> App::_document;

std::shared_ptr<ControllerBase> App::getController(ControllerType type)
{
    static std::shared_ptr<ControllerBase> controller;
    if (!controller)
    {
        switch (type)
        {
        case ControllerType::CLI:
            controller = std::make_shared<CLI::Controller>();
            break;
        
        case ControllerType::GUI:
            controller = std::make_shared<GUI::Controller>();
            break;
        }
    }
    return controller;
}

std::shared_ptr<Document> App::getDocument()
{
    static std::shared_ptr<Document> document;
    if (!document)
    {
        document = std::make_shared<Document>();
    }

    return document;
}


std::shared_ptr<Director> App::getDirector()
{
    static std::shared_ptr<Director> director;
    if (!director)
    {
        director = std::make_shared<Director>();
    }

    return director;
}

std::shared_ptr<Render> App::getRenderer()
{
    static std::shared_ptr<Render> renderer;
    if (!renderer)
    {
        renderer = std::make_shared<Render>();
    }
    
    return renderer;
}
