#include "Director.hpp"

void Director::redo()
{
    if (!redoStack.empty()) 
    {
        auto action = redoStack.top();
        redoStack.pop();
        action->exec();
        undoStack.push(action);
    }
}

void Director::undo()
{
    if (!undoStack.empty())
    {
        auto action = undoStack.top();
        undoStack.pop();
        action->revert();
        redoStack.push(action);
    }
}

void Director::exec(std::shared_ptr<Action> action)
{
    action->exec();
    undoStack.push(action);
}
