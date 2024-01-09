#include "LoadCommand.hpp"

LoadCommand::LoadCommand(const Arguments& arguments)
    : Command(arguments) {}

void LoadCommand::exec()
{
    auto filePathIt = _argumentsMap.find("-filePath");
    if (filePathIt == _argumentsMap.end()) {
        throw InvalidArgumentException("The -filePath argument is undefined.");
    }
    QByteArray byteArrayData;
    const QString& filePath = QString::fromStdString(filePathIt->second);
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        byteArrayData = file.readAll();
        if (byteArrayData.isEmpty()) {
            qDebug() << "File is empty or could not read any data.";
        }
        else {
            qDebug() << "Read" << byteArrayData.size() << "bytes from" << filePath;
        }
        file.close();
    }
    else {
        qDebug() << "Could not open file:" << file.errorString();
    }
    JsonSerializer::getInstance().deserializeDocument(byteArrayData, App::getDocument());
}
