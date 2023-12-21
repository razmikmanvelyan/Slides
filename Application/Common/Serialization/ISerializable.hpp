#pragma once
#include <QByteArray>

class ISerializable {
public:
    virtual ~ISerializable() {}
    virtual QByteArray toSerializedData() const = 0;
    virtual void fromSerializedData(const QByteArray& data) = 0;
};