#pragma once

#include "../Common/Controller/ControllerBase.hpp"
#include "../Common/Exception/Exception.hpp"
#include "Parser/Parser.hpp"
#include "IOController.hpp"

#include <iostream>
#include <string>
namespace CLI {
    class Controller : public ControllerBase
    {
    public:
        Controller();

    public:
        void exit() override;
        void run() override;

    private:
        IOController _io;
        bool _isExit;
    };
};