#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "Memento.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"
#include <vector>

class Canvas {

private:
	std::vector<Shape*> shapes;

public:

	Canvas(int size);
	~Canvas();

	Memento* captureCurrent();
	void undoAction(Memento* prev);

	void addShape(Shape* shape);
	const std::vector<Shape*>& getShapes() const { return shapes; }
};

#endif
