#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Textbox.h"
#include <vector>
#include <memory>

class Memento
{

private:
	// Shape* shapes;
	std::vector<std::shared_ptr<Shape>> shapes;

public:
	// Memento(Shape* elements);
	// ~Memento();
	// Shape* getShape();
	// void setShape(Shape* shape);
	Memento(const std::vector<Shape *> &elements);
	~Memento();

	const std::vector<std::shared_ptr<Shape>> &getShapes() const;
	void setShapes(const std::vector<Shape *> &newShapes);
};

#endif
