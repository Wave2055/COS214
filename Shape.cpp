#include "Shape.h"

int Shape::getLength() {
	return this->length;
}

void Shape::setLength(int length) {
	this->length = length;
}

int Shape::getWidth() {
	return this->width;
}

void Shape::setWidth(int width) {
	this->width = width;
}

string Shape::getColour() {
	return this->colour;
}

void Shape::setColour(string colour) {
	this->colour = colour;
}

int Shape::getPosition_x() {
	return this->position_x;
}

void Shape::setPosition_x(int position_x) {
	this->position_x = position_x;
}

int Shape::getPosition_y() {
	return this->position_y;
}

void Shape::setPosition_y(int position_y) {
	this->position_y = position_y;
}
