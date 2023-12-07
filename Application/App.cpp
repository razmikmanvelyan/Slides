#include "App.hpp"

App::App() : _io( std::cin, std::cout ) , _evaluator(std::make_shared<Document>(_document)) {}

void App::run() {
    while ( true ) {
        try {
            const auto line = _io.getLine();
            auto cmd = _evaluator.evaluate( line );
            cmd->exec();
        }
        catch(const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}