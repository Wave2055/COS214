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


