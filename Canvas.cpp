#include "Canvas.h"

Canvas::Canvas(int choice)
{
	switch(choice)
	{
		case 0: 
			RectangleFactory* fact = new RectangleFactory();
			shapes = fact->createShape();
			delete fact;
			break;

		case 1:
			SquareFactory* fact = new SquareFactory();
			shapes = fact->createShape();
			break;

		case 2: 
			TextboxFactory* fact = new TextboxFactory();
			shapes = fact->createShape();
			delete fact;
			break;

		default:
			shapes = nullptr;
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
