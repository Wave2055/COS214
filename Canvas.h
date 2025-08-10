#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "Memento.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"

class Canvas {

private:
	Shape* shapes;

public:

	Canvas(int size);
	~Canvas();

	Memento* captureCurrent();
	void undoAction(Memento* prev);

	
};

#endif
