#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Textbox.h"
#include <vector>

class Memento {

private:
	// Shape* shapes;
	  std::vector<Shape*> shapes;


public:
	// Memento(Shape* elements);
	// ~Memento();
	// Shape* getShape();
	// void setShape(Shape* shape);
	 Memento(const std::vector<Shape*>& elements);
    ~Memento();

    const std::vector<Shape*>& getShapes() const;
    void setShapes(const std::vector<Shape*>& newShapes);
};

#endif
