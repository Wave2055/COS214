#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "Memento.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"
#include <memory>

class Canvas
{

private:
	std::vector<std::shared_ptr<Shape>> shapes;

public:
	Canvas();
	~Canvas();

	void addShape(Shape *shape);
	Memento *captureCurrent();
	void undoAction(Memento *prev);

	std::string listShapes();
};

#endif
