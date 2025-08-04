#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"

class Textbox : Shape {

public:
	std::string text;

	Textbox();
	Textbox(int l, int w, std::string c, int x, int y, std::string t);
	Textbox(Textbox& copy);
	~Textbox();

	Shape* clone();
};

#endif
