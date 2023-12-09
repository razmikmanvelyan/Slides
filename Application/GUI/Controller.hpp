#pragma once

#include "../Common/Controller/ControllerBase.hpp"

namespace GUI
{

    class Controller : public ControllerBase
    {
    public:
        void run() override;
        void exit() override;
    };

}
