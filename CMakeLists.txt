# CMakeList.txt : CMake project for CommandExecutor, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CommandExecutor")

# Add source to this project's executable.
add_executable (CommandExecutor 

  "CommandExecutor.cpp"
  "CommandExecutor.h"

  "Application/Controller/Evaluator/Commands/Command.hpp"
  "Application/Controller/Evaluator/Commands/CommandFactory.hpp"
  "Application/Controller/Evaluator/Commands/CommandFactory.cpp"
  "Application/Controller/Evaluator/Commands/CommandRegistry.hpp"
  "Application/Controller/Evaluator/Commands/CommandRegistry.cpp"
  "Application/Controller/Evaluator/Commands/AddCommand.hpp"
  "Application/Controller/Evaluator/Commands/AddCommand.cpp"
  "Application/Controller/Evaluator/Commands/NullCommand.hpp"
  "Application/Controller/Evaluator/Commands/NullCommand.cpp"

  "Application/Controller/Evaluator/Commands/Arguments/Argument.hpp"
  "Application/Controller/Evaluator/Commands/Arguments/ArgumentsRegistry.cpp"
  "Application/Controller/Evaluator/Commands/Arguments/Argument.cpp"
  "Application/Controller/Evaluator/Commands/Arguments/ArgumentsRegistry.hpp"
  
  "Application/Controller/Evaluator/Evaluator.hpp"
  "Application/Controller/Evaluator/Evaluator.cpp"
  "Application/Controller/Evaluator/Tokenizer.hpp"
  "Application/Controller/Evaluator/Tokenizer.cpp"

  "Application/Controller/Evaluator/Parser/Parser.hpp"
  "Application/Controller/Evaluator/Parser/Parser.cpp"

  "Application/App.hpp"
  "Application/App.cpp"
  "Application/View/IOController.hpp"
  "Application/View/IOController.cpp"

  "Application/Model/Container.hpp"
  "Application/Model/Container.cpp"
  "Application/Model/IContainer.hpp"
  "Application/Model/IContainerItem.hpp"
  "Application/Model/Document/Document.hpp"
  "Application/Model/Document/Slide.hpp"
  "Application/Model/Document/Slide.cpp"
  "Application/Model/Document/Shape/Shape.hpp"
  "Application/Model/Document/Shape/Rectangle.hpp"
  "Application/Model/Document/Shape/ShapeFactory.hpp"
  "Application/Model/Document/Shape/ShapeFactory.cpp"

)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CommandExecutor PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
