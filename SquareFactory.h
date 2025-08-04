#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

#include "ShapeFactory.h"
#include "Square.h"

class SquareFactory : ShapeFactory {


public:
	SquareFactory();
	~SquareFactory();

	Shape* createShape();

	void toString();
};

#endif
