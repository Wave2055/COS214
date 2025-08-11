#include "ExportCanvas.h"

ExportCanvas::ExportCanvas(Canvas *canvas)
{
	this->canvas = canvas;
}

ExportCanvas::~ExportCanvas()
{
	// if (this->canvas)
	// {
	// 	delete canvas;
	// }
}

void ExportCanvas::exportToFile()
{
	prepareCanvas();
	renderElements();
	saveToFile();
}
