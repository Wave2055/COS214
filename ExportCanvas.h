#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

class ExportCanvas {

private:
	Canvas* canvas;

public:
	void export();

private:
	virtual void prepareCanvas() = 0;

	virtual void renderElements() = 0;

	virtual void saveToFile() = 0;
};

#endif
