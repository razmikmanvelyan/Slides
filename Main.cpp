#include "Application/App.hpp"

using namespace std;

int main()
{	
	std::shared_ptr<ControllerBase> controller;
    controller = App::getController(ControllerType::CLI);
    controller->run();
	return 0;
}
