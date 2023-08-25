all: listQueue

listQueue: main.o list.o queue.o
	g++ -std=c++11 main.o list.o queue.o -o listQueue

main.o: main.cpp list.hpp queue.hpp
	g++ -std=c++11 -c main.cpp

list.o: list.cpp list.hpp
	g++ -std=c++11 -c list.cpp

queue.o: queue.cpp queue.hpp list.hpp
	g++ -std=c++11 -c queue.cpp


clean:
	rm -rf *.o listQueue
