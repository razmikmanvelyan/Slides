// CommandExecutor.cpp : Defines the entry point for the application.
//

#include "CommandExecutor.h"
#include "Application/App.hpp"

using namespace std;

int main()
{	
	App app;
	try{
		app.run();
	}
	catch(const std::runtime_error& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
