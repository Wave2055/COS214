#include "Textbox.h"

Textbox::Textbox():Shape()
{
	this->text = "";
}

Textbox::Textbox(int l, int w, std::string c, int x, int y, std::string t): Shape(l,w,c,x,y)
{
	this->text = t;
}

Textbox::Textbox(Textbox& copy): Shape(copy)
{
	this->text = copy.text;
}

Textbox::~Textbox()
{
	//no dynamic mem
	//automatically calls the Shape destructor
}

Shape* Textbox::clone() 
{
	return new Textbox(*this);
}

std::string Textbox::getText()
{
	return this->text;
}

void Textbox::setText(std::string t)
{
	this->text = t;
}
