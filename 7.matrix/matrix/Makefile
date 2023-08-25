all: matrix

matrix: main.o checkFunction.o matrix.o
	g++ -std=c++11 main.o matrix.o checkFunction.o -o matrix

main.o: main.cpp checkFunction.hpp
	g++ -std=c++11 -c main.cpp

matrix.o: matrix.cpp matrix.hpp
	g++ -std=c++11 -c matrix.cpp

checkFunction.o: checkFunction.cpp checkFunction.hpp
	g++ -std=c++11 -c checkFunction.cpp


clean:
	rm -rf *.o matrix
