#include "Canvas.h"

Canvas::Canvas(int size)
{
	
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
