#include <iostream>
#include "Shape.h"
#include "Canvas.h"
#include "PNGExporter.h"
#include "PDFExporter.h"

int main()
{
    std::cout << "start main" << std::endl;

    Shape **shapes = new Shape *[3];

    RectangleFactory *rect = new RectangleFactory();
    SquareFactory *square = new SquareFactory();
    TextboxFactory *tb = new TextboxFactory();

    shapes[0] = rect->createShape();
    shapes[1] = square->createShape();
    shapes[2] = tb->createShape();

    Canvas *cv = new Canvas();

    for (int i = 0; i < 3; i++)
    {
        cv->addShape(shapes[i]);
    }

    std::cout << cv->listShapes() << std::endl;
    // Memento *save = cv->captureCurrent();

    shapes[0]->setLength(15);
    shapes[0]->setWidth(7);
    shapes[0]->setColour("Green");
    shapes[0]->setPosition_x(15);
    shapes[0]->setPosition_y(7);

    shapes[1]->setLength(32);
    shapes[1]->setWidth(27);
    shapes[1]->setColour("Blue");
    shapes[1]->setPosition_x(68);
    shapes[1]->setPosition_y(57);

    shapes[2]->setLength(28);
    shapes[2]->setWidth(5);
    shapes[2]->setColour("Red");
    shapes[2]->setPosition_x(32);
    shapes[2]->setPosition_y(28);

    std::cout << cv->listShapes() << std::endl; // use this line for object diagram and use a shape from the shapes array
    PDFExporter *pdf = new PDFExporter(cv);
    PNGExporter *png = new PNGExporter(cv);

    png->exportToFile();
    pdf->exportToFile();

    // cv->undoAction(save);
    std::cout << cv->listShapes() << std::endl;

    std::cout << "end main" << std::endl;

    delete rect;
    delete square;
    delete tb;

    for (int i = 0; i < 3; i++)
    {
        if (shapes[i])
        {
            delete shapes[i];
        }
    }

    delete[] shapes;
    // delete cv;
    // delete png;
    // delete pdf;
    //    delete save;
    return 0;
}