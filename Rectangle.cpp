#include "Rectangle.h"

Shape* Rectangle::clone() {
	return new Rectangle(*this);
}
