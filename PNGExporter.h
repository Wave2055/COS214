#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H
#include "ExportCanvas.h"

class PNGExporter : public ExportCanvas
{

public:
	PNGExporter(Canvas *canvas);
	~PNGExporter();

private:
	void saveToFile();

	void prepareCanvas();

	void renderElements();
};

#endif
