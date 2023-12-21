#pragma once
#include "Command.hpp"
#include "../../../App.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QSaveFile>
#include <QDebug>

class LoadCommand : public Command
{
public:
    LoadCommand(const Arguments&);
    void exec() override;
};