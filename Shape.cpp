#include "Shape.h"

Shape::Shape()
{
	this->length = -1;
	this->width =-1; 
	this->colour = "no colour";
	this->position_x = -1;
	this->position_y = -1;
}

Shape::Shape(int l, int w, std::string c, int x, int y)
{
	this->length = l;
	this->width = w; 
	this->colour = c;
	this->position_x = x;
	this->position_y = y;
}

Shape::Shape(Shape& copy)
{
	this->length = copy.length;
	this->width = copy.width;
	this->colour = copy.colour;
	this->position_x = copy.position_x;
	this->position_y = copy.position_y;
}

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

std::string Shape::getColour() {
	return this->colour;
}

void Shape::setColour(std::string colour) {
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
