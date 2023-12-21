#include "ShapeRectangle.hpp"
#include <iostream>

std::shared_ptr<IShape> ShapeRectangle::clone(std::shared_ptr<Item> item) const {
    std::shared_ptr<ShapeRectangle> shape = std::make_shared<ShapeRectangle>();
    shape->setName(item->getShape());
    shape->setColor(item->getColor());
    shape->setBoundingBox(item->getPosition());
    return shape;
}

void ShapeRectangle::draw(QPainter& painter) {
    painter.fillRect(std::get<0>(_boundingBox),
    std::get<1>(_boundingBox),
    std::get<2>(_boundingBox),
    std::get<3>(_boundingBox),
    QColor(QString::fromStdString(_color)));
}