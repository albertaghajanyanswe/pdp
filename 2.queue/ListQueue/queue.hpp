#ifndef QUEUE_H
#define QUEUE_H
#include "list.hpp"

class Queue : private List {
public:
	Queue();
	Queue(const Queue& other);
	~Queue();

	bool isEmpty();
	int getCounts() const;
	int getTop();

	void enqueue(int item);
	void dequeue();
	void printQueue();
};
#endif
