#include "PDFExporter.h"
#include <iostream>
#include <fstream>


void PDFExporter::saveToFile() 
{
    std::ofstream file("output.pdf");
    if (file.is_open()) 
    {
        file << "Exported PDF from Canvas\n";
        file.close();
        std::cout << "PDF File Content saved to output.pdf\n";
    } 
    else 
    {
        std::cout << "Failed to save PDF file.\n";
    }

}

void PDFExporter::prepareCanvas() 
{
    std::cout<< "PDF Canvas Prepared\n";//this does not loook right man.....idk whats supposed to be implemented here
}

void PDFExporter::renderElements() 
{
    std::cout<< "PDF Elements Rendered\n";
	
}
