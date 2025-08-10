#include "Memento.h"

// Memento::Memento(Shape* elements) {
	
// 	this->shapes = elements->clone();
// }
Memento::Memento(const std::vector<Shape*>& elements) {
    // Deep copy all shapes
    for (Shape* s : elements) {
        shapes.push_back(s->clone());
    }
}

Memento::~Memento()
{
	// delete shapes;
	for (Shape* s : shapes) {
        delete s;
    }
    shapes.clear();
}

// Shape* Memento::getShape()
// {
// 	return this->shapes;
// }
const std::vector<Shape*>& Memento::getShapes() const {
    return shapes;
}

// void Memento::setShape(Shape* shape)
// {
// 	this->shapes = shape->clone();
// }
void Memento::setShapes(const std::vector<Shape*>& newShapes) {
    // Clear existing
    for (Shape* s : shapes) {
        delete s;
    }
    shapes.clear();

    // Deep copy new
    for (Shape* s : newShapes) {
        shapes.push_back(s->clone());
    }


}