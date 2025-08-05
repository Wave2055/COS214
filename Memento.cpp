#include "Memento.h"

Memento::Memento(Shape* elements) {
	
	if (Rectangle* r = dynamic_cast<Rectangle*>(elements))
	{
		this->shapes = r->clone();//make sure to deep copy it
	}
	else if (Square* s = dynamic_cast<Square*>(elements))
	{
		this->shapes = s->clone();
	}
	else if (Textbox* t = dynamic_cast<Textbox*>(elements))
	{
		this->shapes = t->clone();
	}
	else 
	{
		this->shapes = nullptr;
	}
}

Shape* Memento::getShape()
{
	return this->shapes;
}
