ofiles = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
gpp = g++ -c -std=c++11 -fprofile-arcs -ftest-coverage -g

main: $(ofiles)
	g++ -std=c++11 -fprofile-arcs -ftest-coverage -g $(ofiles) -o main

#compiles main
TestingMain.o: TestingMain.cpp
	$(gpp) $< -o $@

#compiles all cpp with a matching h file
%.o: %.cpp %.h
	$(gpp) $< -o $@

#runs the main
run: main
	./main

#removes all o files
clean: 
	rm -f *.o main *.gcda *.gcno *.gcov coverage.info coverage-report -r

#check for memory leaks
val:
	g++ -fdiagnostics-color=always -g *.cpp -o main 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main

cov: clean main
	./main
	# Capture coverage
	lcov --capture --directory . --output-file coverage.info
	# Remove system headers
	lcov --remove coverage.info '/usr/*' --output-file coverage.info
	# Generate HTML report
	genhtml coverage.info --output-directory coverage-report
	@echo "Coverage report ready at coverage-report/index.html"

docs: 
	doxygen Doxyfile
