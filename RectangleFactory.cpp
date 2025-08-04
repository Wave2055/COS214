#include "RectangleFactory.h"

RectangleFactory::RectangleFactory(): ShapeFactory()
{
}

RectangleFactory::~RectangleFactory()
{
}

Shape* RectangleFactory::createShape() {
	return new Rectangle();
}

void RectangleFactory::toString() {
	// TODO - implement RectangleFactory::toString
	throw "Not yet implemented";
}
