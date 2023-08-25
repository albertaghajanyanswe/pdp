all: deque

deque: main.o deque.o
	g++ -std=c++11 main.o deque.o -o deque

main.o: main.cpp deque.hpp
	g++ -std=c++11 -c main.cpp

deque.o: deque.cpp deque.hpp
	g++ -std=c++11 -c deque.cpp

clean:
	rm -rf *.o deque
