#include "TextboxFactory.h"

TextboxFactory::TextboxFactory():ShapeFactory()
{
}

TextboxFactory::~TextboxFactory()
{
	//no dynamic mem
}

Shape* TextboxFactory::createShape() {
	return new Textbox();
}


