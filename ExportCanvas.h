#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

#include "Canvas.h"

class ExportCanvas
{

private:
	Canvas *canvas;

public:
	ExportCanvas(Canvas *canvas);
	~ExportCanvas();

	void exportToFile();

private:
	virtual void prepareCanvas() = 0;

	virtual void renderElements() = 0;

	virtual void saveToFile() = 0;
};

#endif
