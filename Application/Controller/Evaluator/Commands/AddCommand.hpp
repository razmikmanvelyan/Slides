#pragma once

#include "Command.hpp"
#include "../../../Model/Document/Document.hpp"
#include "../../../Model/Document/Shape/ShapeFactory.hpp"


class AddCommand : public Command{
public:
    AddCommand( const Arguments& arguments, std::shared_ptr<Document> document) : Command(arguments), _document(document) {}

    void exec() override;

private:
    bool validateArguments() override;

private:
    std::shared_ptr<Document> _document;
};
