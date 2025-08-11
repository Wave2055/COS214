#include "PNGExporter.h"
#include <fstream>
#include <iostream>

PNGExporter::PNGExporter(Canvas *canvas) : ExportCanvas(canvas)
{
}

PNGExporter::~PNGExporter()
{
}

void PNGExporter::saveToFile()
{
    std::ofstream file("output.png");
    if (file.is_open())
    {
        file << "Exported PNG from Canvas\n";
        file.close();
        std::cout << "PNG File Content saved to output.png\n";
    }
    else
    {
        std::cout << "Failed to save PNG file.\n";
    }
}

void PNGExporter::prepareCanvas()
{
    std::cout << "PNG Canvas Prepared\n"; // sus man
}

void PNGExporter::renderElements()
{
    std::cout << "PNG Elements Rendered\n";
}
