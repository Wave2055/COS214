#include "Memento.h"

// Memento::Memento(Shape* elements) {

// 	this->shapes = elements->clone();
// }
Memento::Memento(const std::vector<Shape *> &elements)
{
    // Deep copy all shapes
    for (Shape *s : elements)
    {
        shapes.push_back(std::shared_ptr<Shape>(s->clone()));
    }

    for (Shape *s : elements)
    {
        if (s)
        {
            delete s;
        }
    }
}

Memento::~Memento()
{
}

// Shape* Memento::getShape()
// {
// 	return this->shapes;
// }
const std::vector<std::shared_ptr<Shape>> &Memento::getShapes() const
{
    return shapes;
}

// void Memento::setShape(Shape* shape)
// {
// 	this->shapes = shape->clone();
// }
void Memento::setShapes(const std::vector<Shape *> &newShapes)
{
    // Clear existing

    // Deep copy new
    for (Shape *s : newShapes)
    {
        shapes.push_back(std::shared_ptr<Shape>(s->clone()));
    }
}