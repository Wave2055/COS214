#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "Rectangle.h"
#include "ShapeFactory.h"

class RectangleFactory : public ShapeFactory
{

public:
	RectangleFactory();
	~RectangleFactory();

	Shape *createShape();

	
};

#endif
