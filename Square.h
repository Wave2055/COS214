#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {


public:

	Square();
	Square(int l, int w, std::string c, int x, int y);
	Square(Square& copy);

	~Square();

	Shape* clone();
};

#endif
