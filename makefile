ofiles = main.o Shape.o Rectangle.o Square.o Textbox.o ShapeFactory.o RectangleFactory.o SquareFactory.o TextboxFactory.o Canvas.o Memento.o ExportCanvas.o PDFExporter.o PNGExporter.o
gpp = g++ -c -std=c++11

main: $(ofiles)
	g++ -std=c++11 $(ofiles) -o main

main.o: Main.cpp
	$(gpp) $< -o $@

%.o: %.cpp %.h
	$(gpp) $< -o $@

run: main
	./main

clean: 
	rm -f *.o main

val:
	g++ -fdiagnostics-color=always -g *.cpp -o main 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main
