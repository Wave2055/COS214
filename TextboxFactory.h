#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

#include "ShapeFactory.h"
#include "Textbox.h"

class TextboxFactory : ShapeFactory {


public:
	TextboxFactory();
	~TextboxFactory();

	Shape* createShape();

	void toString();
};

#endif
