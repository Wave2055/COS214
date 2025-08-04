#ifndef SHAPE_H
#define SHAPE_H

class Shape {

private:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;

public:
	int getLength();

	void setLength(int length);

	int getWidth();

	void setWidth(int width);

	string getColour();

	void setColour(string colour);

	int getPosition_x();

	void setPosition_x(int position_x);

	int getPosition_y();

	void setPosition_y(int position_y);

	virtual Shape* clone() = 0;
};

#endif
