#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H
#include "Canvas.h"
#include "ExportCanvas.h"

class PDFExporter : ExportCanvas {


private:
	void saveToFile();

	void prepareCanvas();

	void renderElements();
};

#endif
