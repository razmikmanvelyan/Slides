#pragma once
#include "ISerializable.hpp"
#include <QJsonObject>
#include <QJsonDocument>

class JsonSerializable : public virtual ISerializable{
public:
    virtual ~JsonSerializable() {}
    virtual QJsonObject toJson() const = 0;
    virtual void fromJson(const QJsonObject&) = 0;

    virtual QByteArray toSerializedData() const override;

    virtual void fromSerializedData(const QByteArray&) override;
};