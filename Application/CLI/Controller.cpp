#include "Controller.hpp"

namespace CLI
{

    Controller::Controller()
        : _isExit(false) {}

    void Controller::run()
    {
        Parser cmdParser;

        while (!_isExit)
        {
            try
            {
                auto cmd = cmdParser.parse(_io.getLine());
                cmd->exec();
            }
            catch(const Exception& exc)
            {
                std::cerr <<exc.what() <<'\n';
            }
        }
    }

    void Controller::exit()
    {
        _isExit = true;
    }
}