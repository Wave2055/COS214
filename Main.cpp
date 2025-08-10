#include <iostream>
#include "Shape.h"
#include "Canvas.h"


int main()
{
    std::cout << "start main" << std::endl;

    Shape** shapes = new Shape*[3];

    RectangleFactory* rect = new RectangleFactory();
    SquareFactory* square = new SquareFactory();
    TextboxFactory* tb = new TextboxFactory();

    shapes[0] = rect->createShape();
    shapes[1] = square->createShape();
    shapes[2] = tb->createShape();


    std::cout << "end main" << std::endl;

    delete rect; 
    delete square;
    delete tb;

    for (int i =0 ; i < 3; i++)
    {
        if (shapes[i])
        {
            delete shapes[i];
        }
    }

    delete [] shapes;
    return 0;
}