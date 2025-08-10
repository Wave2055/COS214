#include "Canvas.h"

Canvas::Canvas(int size)
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
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}

Memento* Canvas::captureCurrent() {
    // You may want to implement deep copy for all shapes
    return new Memento(this->shapes.empty() ? nullptr : shapes.back());
}

void Canvas::undoAction(Memento* prev) {
    // This is a placeholder; you may want to clear and restore all shapes
    if (!shapes.empty()) {
        delete shapes.back();
        shapes.pop_back();
    }
    Shape* restored = prev->getShape()->clone();
    shapes.push_back(restored);
}