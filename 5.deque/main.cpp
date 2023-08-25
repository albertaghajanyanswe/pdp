#include <cstdlib>
#include <iostream>
#include "deque.hpp"

int main(int argc, char** argv) {
    Deque myDeque;
    int choose = 0;
    while (12 != choose) {
        switch (choose) {
            case 1:
                int item;
                std::cout << "Item: ";
                std::cin >> item;
                myDeque.push_front(item);
                break;
            case 2:
                std::cout << "Item: ";
                std::cin >> item;
                myDeque.push_back(item);
                break;
            case 3:
                myDeque.pop_front();
                break;
            case 4:
                myDeque.pop_back();
                break;
            case 5:
                std::cout << "Item: ";
                std::cin >> item;
                myDeque.pop_byData(item);
                break;
            case 6:
                if(myDeque.empty()) {
                    std::cout << "\nDeque is empty\n";
                } else {
                    std::cout << "\nDeque is not empty\n";
                }
                break;
            case 7:
                myDeque.printDeque();
                break;
            case 8:
                int index;
                std::cout << "Index: ";
                std::cin >> index;
                std::cout << "Item: ";
                std::cin >> item;
                myDeque.insert(index,item);
                break;
            case 9:
                myDeque.clear();
                break;

            case 10:
                std::cout << "\nCount is: " << myDeque.count() << "\n";
                break;
            case 11:
                std::cout<<"Index: ";
                std::cin >> index;
                myDeque.operator[](index);
                break;
        }
        std::cout << std::endl << "1-Push_front, 2-Push_back, 3-Pop_front, 4-Pop_back, 5-PopByData\n6-Empty, 7-Print, 8-Insert, 9-Clear,10-Count, 11-Operator[ ], 12-Exit ---> ";
        std::cin >> choose;
        std::cout << std::endl;
    }
    return 0;
}

