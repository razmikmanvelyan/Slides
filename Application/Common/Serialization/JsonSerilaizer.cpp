#include "JsonSerializer.hpp"

std::unique_ptr<JsonSerializer> JsonSerializer::instance = nullptr;

JsonSerializer& JsonSerializer::getInstance() {
    if (!instance) {
        instance.reset(new JsonSerializer());
    }
    return *instance;
}

QByteArray JsonSerializer::serializeDocument(const std::shared_ptr<Document> document){
    QJsonObject obj;
    QJsonArray slidesArray;
    for (const auto& slide : document->getSlides()) {
        QJsonObject slideObj = this->serializeSlide(slide);
        slidesArray.append(slideObj);
    }
    obj["slides"] = slidesArray;
    return QJsonDocument(obj).toJson();
}

void JsonSerializer::deserializeDocument(const QByteArray& data, std::shared_ptr<Document> document) {
    QJsonObject jsonObject = QJsonDocument::fromJson(data).object();
    QJsonArray slidesArray = jsonObject["slides"].toArray();
    for (const auto& slideValue : slidesArray) {
        QJsonObject slideObj = slideValue.toObject();
        auto newSlide = std::make_shared< Slide >();
        this->deserializeSlide(slideObj, newSlide);
        document->addSlide(newSlide);
    }
}


QJsonObject JsonSerializer::serializeItem(const std::shared_ptr<Item> item) {
    QJsonObject json;
    json["id"] = item->getId();
    json["shape"] = QString::fromStdString(item->getShape());
    json["color"] = QString::fromStdString(item->getColor());
    json["text"] = QString::fromStdString(item->getText());
    json["tl_x"] = std::get<0>(item->getPosition());
    json["tl_y"] = std::get<1>(item->getPosition());
    json["rb_x"] = std::get<2>(item->getPosition());
    json["rb_y"] = std::get<3>(item->getPosition());
    return json;
}

void JsonSerializer::deserializeItem(const QJsonObject& jsonObject, std::shared_ptr<Item> item) {
    if (jsonObject.contains("id") && jsonObject["id"].isDouble())
    {
        item->setId(jsonObject["id"].toInt());
    }
    if (jsonObject.contains("shape") && jsonObject["shape"].isString())
    {
        item->setShape(jsonObject["shape"].toString().toStdString());
    }
    if (jsonObject.contains("color") && jsonObject["color"].isString())
    {
        item->setColor(jsonObject["color"].toString().toStdString());
    }
    if (jsonObject.contains("text") && jsonObject["text"].isString())
    {
        item->setText(jsonObject["text"].toString().toStdString());
    }
    if (jsonObject.contains("tl_x") && jsonObject["tl_x"].isDouble()
        && jsonObject.contains("tl_y") && jsonObject["tl_y"].isDouble()
        && jsonObject.contains("rb_x") && jsonObject["rb_x"].isDouble()
        && jsonObject.contains("rb_y") && jsonObject["rb_y"].isDouble())
    {
        item->setPosition(std::make_tuple(jsonObject["tl_x"].toInt(), jsonObject["tl_y"].toInt(), jsonObject["rb_x"].toInt(), jsonObject["rb_y"].toInt()));
    }
}

QJsonObject JsonSerializer::serializeSlide(const std::shared_ptr<Slide> slide) {
    QJsonObject json;
    json["id"] = slide->getId();
    int index = 0;
    for (const auto& item : slide->getItems()) {
        json[QString("item%1").arg(index++)] = JsonSerializer::serializeItem(item);
    }
    return json;
}

void JsonSerializer::deserializeSlide(const QJsonObject& jsonObject, std::shared_ptr<Slide> slide) {
    slide->getItems().clear();
    if (jsonObject.contains("id") && jsonObject["id"].isDouble())
    {
        slide->setId(jsonObject["id"].toInt());
    }
    for (const auto& key : jsonObject.keys())
    {
        if (key.startsWith("item"))
        {
            auto newItem = std::make_shared< Item >();
            JsonSerializer::deserializeItem(jsonObject[key].toObject(), newItem);
            slide->getItems().push_back(newItem);
        }
    }
}