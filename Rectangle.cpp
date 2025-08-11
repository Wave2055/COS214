#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
}

Rectangle::Rectangle(int l, int w, std::string c, int x, int y) : Shape(l, w, c, x, y)
{
}

Rectangle::Rectangle(Rectangle &copy) : Shape(copy)
{
}

Rectangle::~Rectangle()
{
	// no dynamic mem
	// automatically calls shape destructor
}

Shape *Rectangle::clone()
{
	return new Rectangle(*this);
}

std::string Rectangle::toString()
{
	std::string out = "Rectangle\n" + Shape::toString();
	return out;
}
