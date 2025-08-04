#include "Square.h"

Square::Square():Shape()
{
}

Square::Square(int l, int w, std::string c, int x, int y): Shape(l,w,c,x,y)
{
}

Square::Square(Square& copy):Shape(copy)
{
}

Square::~Square()
{
	//no dynamic mem
	//automatically calls the Shape destructor
}

Shape* Square::clone() {
	return new Square(*this);
}
