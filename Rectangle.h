#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : Shape {


public:
	Rectangle();

	Rectangle(int l, int w, std::string c, int x, int y);

	Rectangle (Rectangle& copy);

	~Rectangle();

	Shape* clone();
};

#endif
