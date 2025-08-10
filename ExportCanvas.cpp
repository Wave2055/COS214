#include "ExportCanvas.h"

void ExportCanvas::exportToFile() {
	prepareCanvas();
	renderElements();	
	saveToFile();
}
