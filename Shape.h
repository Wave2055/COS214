#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{

private:
	int length;
	int width;
	std::string colour;
	int position_x;
	int position_y;

public:
	Shape();
	Shape(int l, int w, std::string c, int x, int y);
	Shape(const Shape &copy);
	virtual ~Shape();

	int getLength();
	void setLength(int length);

	int getWidth();
	void setWidth(int width);

	std::string getColour();
	void setColour(std::string colour);

	int getPosition_x();
	void setPosition_x(int position_x);

	int getPosition_y();
	void setPosition_y(int position_y);

	virtual Shape *clone() = 0;

	virtual std::string toString();
};

#endif
