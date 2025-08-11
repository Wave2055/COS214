#include "SquareFactory.h"

SquareFactory::SquareFactory():ShapeFactory()
{
}

SquareFactory::~SquareFactory()
{
	//no dynamic mem
}

Shape* SquareFactory::createShape() {
	return new Square();
}


