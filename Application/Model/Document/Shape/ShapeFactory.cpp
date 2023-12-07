#include "ShapeFactory.hpp"

std::unique_ptr<Shape> ShapeFactory::create( const Arguments& params )
{
    Argument shapeNameArg = params.at( "-name" );
    std::unique_ptr< Shape > shape;

    if (shapeNameArg._value == "Rect" )
    {
        shape = std::make_unique< Rectangle >();   
    }

    if ( params.find("-color") != params.end() )
    {
        shape->setColor( params.at("-color")._value);
    }

    return shape;
}