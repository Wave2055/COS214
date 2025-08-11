#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H
#include "Canvas.h"
#include "ExportCanvas.h"

class PDFExporter : public ExportCanvas
{

public:
	PDFExporter(Canvas *canvas);
	~PDFExporter();

private:
	void saveToFile();

	void prepareCanvas();

	void renderElements();
};

#endif
