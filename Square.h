#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{

public:
	Square();
	Square(int l, int w, std::string c, int x, int y);
	Square(const Square &copy);

	~Square();

	Shape *clone();

	std::string toString();
};

#endif
