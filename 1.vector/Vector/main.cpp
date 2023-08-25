#include <iostream>
#include "vector.hpp"

int main() {
	Vector vec(5);
	int choose = 0;
	while (choose != 6) {
		switch (choose){
		case 1:
			std::cout << "Vector Size = " << vec.getSize() << std::endl;
			break;
		case 2:
			int index;
			int value;
			std::cout << "index: ";
			std::cin >> index;
			std::cout << "value: ";
			std::cin >> value;
			vec.insert(index,value);
			break;
		case 3:
			std::cout << "index: ";
			std::cin >> index;
			vec.remove(index);
			break;
		case 4:
			std::cout << "index: ";
			std::cin >> index;
			std::cout << index << "  ->  " << vec.retrieve(index) << std::endl;
			break;
		case 5:
			vec.Show();
			break;
		}
		std::cout << std::endl << "1-getSize(), 2-Insert(), 3-Remove(),4-Retrieve(), 5-Show(), 6-Exit ---> ";
		std::cin >> choose;
		std::cout << std::endl;
	}
	return 0;
}
