#include "Canvas.h"

Canvas::Canvas()
{
}

Canvas::~Canvas()
{
	for (Shape *shape : shapes)
	{
		if (shape)
		{
			delete shape;
		}
	}

	shapes.clear();
}
void Canvas::addShape(Shape *shape)
{
	if (shape)
	{
		shapes.push_back(shape);
	}
}

Memento *Canvas::captureCurrent()
{
	// You may want to implement deep copy for all shapes
	// return new Memento(this->shapes.empty() ? nullptr : shapes.back());
	std::vector<Shape *> shapeCopies;
	for (Shape *s : shapes)
	{
		shapeCopies.push_back(s->clone()); // assumes Shape has clone()
	}
	return new Memento(shapeCopies);
}

void Canvas::undoAction(Memento *prev)
{
	// This is a placeholder; you may want to clear and restore all shapes
	// if (!shapes.empty()) {
	//     delete shapes.back();
	//     shapes.pop_back();
	// }
	// Shape* restored = prev->getShape()->clone();
	// shapes.push_back(restored);
	if (!prev)
		return;

	// Clear current shapes
	for (Shape *s : shapes)
	{
		if (s)
		{
			delete s;
		}
	}
	shapes.clear();

	// Restore from memento
	const std::vector<Shape *> &savedShapes = prev->getShapes();
	for (Shape *s : savedShapes)
	{
		shapes.push_back(s->clone());
	}
}

std::string Canvas::listShapes()
{
	std::string out = "";

	for (Shape *shape : shapes)
	{
		out += shape->toString() + "\n\n";
	}

	return out;
}