#include "Memento.h"

Memento::Memento(Shape* elements) {
	
	this->shapes = elements->clone();
}

Memento::~Memento()
{
	delete shapes;
}

Shape* Memento::getShape()
{
	return this->shapes;
}

void Memento::setShape(Shape* shape)
{
	this->shapes = shape->clone();
}


