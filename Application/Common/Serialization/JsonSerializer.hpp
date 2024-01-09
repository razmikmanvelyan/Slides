#pragma once
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "ISerializer.hpp"

class JsonSerializer : ISerializer{
public:
    JsonSerializer(const JsonSerializer&) = delete;
    JsonSerializer& operator=(const JsonSerializer&) = delete;

    static JsonSerializer& getInstance();

    virtual QByteArray serializeDocument(const std::shared_ptr<Document>) override;
    virtual void deserializeDocument(const QByteArray&, std::shared_ptr<Document>) override;

private:
    JsonSerializer() {}

private:
    QJsonObject serializeItem(const std::shared_ptr<Item>);
    void deserializeItem(const QJsonObject&, std::shared_ptr<Item>);
    QJsonObject serializeSlide(const std::shared_ptr<Slide>);
    void deserializeSlide(const QJsonObject&, std::shared_ptr<Slide>);

private:
    static std::unique_ptr<JsonSerializer> instance; // Singleton instance

};