#include "ExportCanvas.h"

ExportCanvas::ExportCanvas(Canvas *canvas)
{
	this->canvas = canvas;
}

ExportCanvas::~ExportCanvas()
{
	delete canvas;
}

void ExportCanvas::exportToFile()
{
	prepareCanvas();
	renderElements();
	saveToFile();
}
