#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H

class PNGExporter : ExportCanvas {


private:
	void saveToFile();

	void prepareCanvas();

	void renderElements();
};

#endif
