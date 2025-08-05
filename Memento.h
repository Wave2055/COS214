#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Textbox.h"

class Memento {

private:
	Shape* shapes;

public:
	Memento(Shape* elements);
	Shape* getShape();
};

#endif
