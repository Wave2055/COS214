#include "Square.h"

Square::Square() : Shape()
{
	this->setWidth(this->getLength());
}

Square::Square(int l, int w, std::string c, int x, int y) : Shape(l, w, c, x, y)
{
}

Square::Square(const Square &copy) : Shape(copy)
{
}

Square::~Square()
{
	// no dynamic mem
	// automatically calls the Shape destructor
}

Shape *Square::clone()
{
	return new Square(*this);
}

std::string Square::toString()
{
	std::string out = "Square\n" + Shape::toString();
	return out;
}
