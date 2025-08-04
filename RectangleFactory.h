#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "Rectangle.h"
#include "ShapeFactory.h"

class RectangleFactory : ShapeFactory {


public:
	RectangleFactory();
	~RectangleFactory();

	Shape* createShape();

	void toString();
};

#endif
