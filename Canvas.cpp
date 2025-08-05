#include "Canvas.h"

Canvas::Canvas(std::string s)
{
	if (s=="rectangle" || s == "Rectangle" || s == "RECTANGLE" || s == "rECTANGLE")
	{
		RectangleFactory* fact = new RectangleFactory();
		shapes = fact->createShape();
	}
	else if (s == "square" || s =="Square" || s=="SQUARE" || s=="sQUARE")
	{
		SquareFactory* fact = new SquareFactory();
		shapes = fact->createShape();
	}
	else if (s == "textbox" || s=="Textbox" || s=="textBox" || s=="TextBox" || s=="TEXTBOX" || s=="tEXTBOX" || s=="tEXTbOX" || s=="TEXTbOX")
	{
		TextboxFactory* fact = new TextboxFactory();
		this->shapes = fact->createShape();
	}
	else
	{
		this->shapes = nullptr;
	}
}


Canvas::~Canvas()
{
	delete shapes;
}

Memento* Canvas::captureCurrent() {
	
	return new Memento (this->shapes);
}

void Canvas::undoAction(Memento* prev) {
	this->shapes = prev->getShape()->clone();
}
