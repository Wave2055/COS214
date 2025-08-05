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

Memento* Canvas::captureCurrent() {
	// TODO - implement Canvas::captureCurrent
	throw "Not yet implemented";
}

void Canvas::undoAction(Memento* prev) {
	// TODO - implement Canvas::undoAction
	throw "Not yet implemented";
}
