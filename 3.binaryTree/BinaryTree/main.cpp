#include <iostream>
#include "binaryTree.hpp"

int main() {
    BinaryTree tree;
    BinaryTree balansTree;
    int choose = 0;
    while (choose != 10) {
        switch (choose) {
            case 1:
		    int value;
                std::cout << "Input value: ";
                std::cin >> value;
                tree.insert(value);
                break;
            case 2:
                std::cout << "Input value: ";
                std::cin >> value;
                if (tree.find(value)) {
                    std::cout << "\nValue found\n";
                } else {
                    std::cout << "\nValue not found\n";
                }
                break;
            case 3:
                std::cout << "\nHeight = " << tree.height() << std::endl;
                break;
            case 4:
                std::cout << "\nSize = " << tree.size() << std::endl;
                break;
            case 5:
                std::cout << "*** Binary Tree ***\n";
                tree.travers();
                break;
            case 6:
                if (tree.isEmpty()) {
                    std::cout << "\nTree is empty\n";
                } else {
                    std::cout << "\nTree is not empty\n";
                }
                break;
            case 7:
                std::cout << "Value: ";
                std::cin >> value;
                balansTree.balancedInsert(value);
                break;
            case 8:
                std::cout << "\nBalanced Height = " << balansTree.height() << std::endl;
                break;
            case 9:
                std::cout << "\nBalanced Binery Tree\n";
                balansTree.travers();
                break;
        }
        std::cout << "\n1-Insert(), 2-Find(), 3-Height(), 4-Size()\n";
        std::cout << "5-Print(), 6-Empty(),7-balancedInsert()\n";
        std::cout << "8-BalancedHeight(), 9-PrintBalancedTree(), 10-Exit: ";
        std::cin >> choose;
    }

    return 0;
}
