#include "JsonSerializable.hpp"

QByteArray JsonSerializable::toSerializedData() const {
    QJsonObject jsonObject = toJson();
    return QJsonDocument(jsonObject).toJson();
}

void JsonSerializable::fromSerializedData(const QByteArray& data) {
    QJsonObject jsonObject = QJsonDocument::fromJson(data).object();
    fromJson(jsonObject);
}