#include <iostream>
#include "list.hpp"
#include "queue.hpp"

int main() {
	Queue myQueue;
	int choose = 0;
	while (choose != 7) {
		switch (choose){
		case 1:
			if (myQueue.isEmpty()) {
				std::cout << "\nQueue is empty\n";
			} else {
				std::cout << "\nQueue not empty\n";
			}
			break;
		case 2:
			std::cout << "\nCount is: " << myQueue.getCounts() << std::endl;
			break;
		case 3:
			int index;
			if (myQueue.getTop() >= 0) {
				std::cout << "Top  ->  " << myQueue.getTop() << std::endl;
			}
			break;
		case 4:
			int item;
			std::cout << "Item: ";
			std::cin >> item;
			myQueue.enqueue(item);
			break;
		case 5:
			myQueue.dequeue();
			break;
		case 6:
			myQueue.printQueue();
			break;
		}
		std::cout << std::endl << "1 - isEmpty(), 2 - getCount(), 3 - getTop(),4 - Enqueue(),\n5 - Dequeue(), 6 - PrintQueue(), 7 - Exit --------> ";
		std::cin >> choose;
		std::cout << std::endl;
	}
	return 0;
}

