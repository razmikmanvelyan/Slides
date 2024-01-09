#include "SaveCommand.hpp"

SaveCommand::SaveCommand(const Arguments& arguments)
    : Command(arguments) {}

void SaveCommand::exec()
{
    auto filePathIt = _argumentsMap.find("-filePath");
    if (filePathIt == _argumentsMap.end()) {
        throw InvalidArgumentException("The -filePath argument is undefined.");
    }
    const QString& filePath = QString::fromStdString(filePathIt->second);
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        qint64 bytesWritten = file.write(JsonSerializer::getInstance().serializeDocument(App::getDocument()));
        if (bytesWritten == -1) {
            qDebug() << "Error writing to file:" << file.errorString();
        }
        else {
            qDebug() << "Successfully wrote" << bytesWritten << "bytes to" << filePath;
        }
        file.close();
    }
    else {
        qDebug() << "Could not open file:" << file.errorString();
    }
}

