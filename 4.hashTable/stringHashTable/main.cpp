#include <iostream>
#include "hashTable.hpp"

int main() {
    HashTable hash;
    std::string key;
    int value;
    int choose = 0;
    while (choose != 9) {
        switch (choose){
            case 1:
                std::cout << "Key: ";
                std::cin >> key;
                std::cout << "Value: ";
                std::cin >> value;
                hash.add(key, value);
                if (std::cin.fail()) {
                    std::cout << "\nInvalid Value\n";
                    return 0;
                }
                break;
            case 2:
                value = 0;
                std::cout << "Key: ";
                std::cin >> key;
                if (hash.findValueByKey(key, value)) {
                    std::cout << "\nKey     Value\n";
                    std::cout << key << "   ->   " << value << std::endl;
                }
                break;
            case 3:
                key = '\0';
                std::cout << "Value: ";
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cout << "\nInvalid Value\n";
                    return 0;
                }
                if (hash.findKeyByValue(key, value)) {
                    std::cout << "\nValue   Key\n";
                    std::cout << value << "   ->   " << key << std::endl;
                } else {
                    std::cout << "\nMutqagrac Value-ov Key chka listum\n" << std::endl;
                }
                break;
            case 4:
                std::cout << "Elementneri qanak@  ->  " << hash.getSize() << std::endl;
                break;
            case 5:
                if(hash.isEmpty()) {
                    std::cout << "\nHashTable is Empty!!!\n";
                } else {
                    std::cout << "\nHashTable is not empty!!!\n";
                }
                break;
            case 6:
                hash.print();
                break;
            case 7:
                std::cout << "Key: ";
                std::cin >> key;
                if (hash.deleteByKey(key, value)) {
                    std::cout << "Key\tValue\n";
                    std::cout << key << "    ->   " << value << "      deleted" << std::endl;
                } else {
                    std::cout << "Key = " << key << " arjeq chka HashTable-um" << std::endl;
                }
                break;
            case 8:
                hash.clearAll();
        }
        std::cout << std::endl << "1-Insert(), 2-findValue(), 3-findKey(), 4-getSize(), 5-isEmpty()\n6-Print(), 7-DeleteByKey(), 8-ClearAll(), 9-Exit -----> ";
        std::cin >> choose;
        std::cout << std::endl;
    }
    return 0;
}

