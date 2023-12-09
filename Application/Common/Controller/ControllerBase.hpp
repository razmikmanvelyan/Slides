#pragma once
class ControllerBase
{

public:
    virtual ~ControllerBase() {}
    virtual void exit() = 0;
    virtual void run() = 0;
};  

enum class ControllerType
{
    CLI,
    GUI
};