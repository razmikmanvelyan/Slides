#pragma once

// #include "GUI/Controller.hpp"
#include "CLI/Controller.hpp"
#include "GUI/Controller.hpp"
#include "Document/Document.hpp"
#include "Director/Director.hpp"
#include "Rendering/Renderer.hpp"
#include <memory>

class Document;
class Director;
class Renderer;

class App
{
public:

    static std::shared_ptr<ControllerBase> getController(ControllerType type = ControllerType::CLI);
    static std::shared_ptr<Document> getDocument();
    static std::shared_ptr<Director> getDirector();
    static std::shared_ptr<Renderer> getRenderer();

private:
    App() {}
    ~App() {} 
    App(const App&);
    App& operator=(const App&);

private:
    static std::shared_ptr<ControllerBase> _controller;
    static std::shared_ptr<Document> _document;
};