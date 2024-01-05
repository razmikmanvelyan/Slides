#include "ShapeRectangle.hpp"
#include <iostream>

std::shared_ptr<IShape> ShapeRectangle::clone(std::shared_ptr<Item> item) const {
    std::shared_ptr<ShapeRectangle> shape = std::make_shared<ShapeRectangle>();
    shape->setName(item->getShape());
    shape->setText(item->getText());
    shape->setColor(item->getColor());
    shape->setBoundingBox(item->getPosition());
    return shape;
}

void ShapeRectangle::draw(QPainter& painter) {

    int x1 = std::get<0>(_boundingBox);   
    int y1 = std::get<1>(_boundingBox);   
    int x2 = std::get<2>(_boundingBox);   
    int y2 = std::get<3>(_boundingBox);  
    QRect rect;
    rect.setCoords(x1, y1, x2, y2);
    painter.fillRect(rect, QColor(QString::fromStdString(_color)));
    //std::cout << _text << std::endl;
    painter.drawText(rect, Qt::AlignCenter, QString::fromStdString(_text));

}