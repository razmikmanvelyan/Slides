#pragma once
#include <QByteArray>
#include "../../Document/Document.hpp"

class ISerializer {
public:
    virtual ~ISerializer() = default;
    virtual QByteArray serializeDocument(const std::shared_ptr<Document>) = 0;
    virtual void deserializeDocument(const QByteArray&, std::shared_ptr<Document>) = 0;
};