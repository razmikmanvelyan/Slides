#pragma once
#include <string>
#include <memory>
#include "CommandRegistry.hpp"

#include "AddCommand.hpp"
#include "NullCommand.hpp"

class Application;
class IOManager;
class Document;

class CommandFactory
{
public:
    static std::unique_ptr< Command > create(const std::string&, const Arguments&, std::shared_ptr<Document>);
};
