#include "queue.hpp"
#include <iostream>

Queue::Queue() {
}

Queue::Queue(const Queue& other)
	: List(other)

 {}
Queue::~Queue() {
}


bool Queue::isEmpty() {
	return List::isEmpty();
}
int Queue::getTop() {
	return retrieve(0);
}

void Queue::enqueue(int item) {
	insert(0, item);
}

void Queue::dequeue() {
	remove(getCounts()-1);
	std::cout << "Delete Top\n";
}

void Queue::printQueue() {
	printList();
}
int Queue::getCounts()const {
	return getCount();
}
