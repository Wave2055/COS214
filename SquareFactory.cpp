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

void SquareFactory::toString() {
	// TODO - implement SquareFactory::toString
	throw "Not yet implemented";
}
