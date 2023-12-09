#pragma once

#include "Actions/Action.hpp"

#include <stack>
#include <memory>

class Director
{
public:
    Director() = default;

public:
    void undo();
    void redo();
    void exec(std::shared_ptr<Action>);

private:
    std::stack<std::shared_ptr<Action>> undoStack;
    std::stack<std::shared_ptr<Action>> redoStack;
};