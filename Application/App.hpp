#pragma once
#include "View/IOController.hpp"
#include "Controller/Evaluator/Evaluator.hpp"

class App {

public:
    App();

public:
    void run();

private:
    IOController _io;
    Evaluator _evaluator;
    Document _document;
};