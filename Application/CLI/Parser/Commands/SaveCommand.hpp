#pragma once
#include "Command.hpp"
#include "../../../App.hpp"
#include "../../../Common/Serialization/JsonSerializer.hpp"
#include <QJsonDocument>
#include <QFile>
#include <QSaveFile>
#include <QDebug>
class SaveCommand : public Command
{
public:
    SaveCommand(const Arguments&);
    void exec() override;
};