#include "binaryTree.hpp"
#include <iostream>

/*   Default Constructor */

BinaryTree::BinaryTree()
   : root(nullptr)
{ }

/*   Copy Constructor   */

BinaryTree::BinaryTree(const BinaryTree& orig)
    :root(nullptr)
{
    std::cout << "\nCopy Constructor called\n";
    root = copyTree(orig.root);
}

BinaryTree::node* BinaryTree::copyTree(node* other) {
    if (nullptr == other) {
        return nullptr;
    }
    node* newNode = new node(other->data);
    newNode -> left = copyTree(other -> left);
    newNode -> right = copyTree(other -> right);
    return newNode;
}

/*  Destructor   */

BinaryTree::~BinaryTree() {
    remove(root);
}

/*   Empty   */

bool BinaryTree::isEmpty() {
    return nullptr == root;
}

/*   Insert   */

void BinaryTree::insert(int value) {
    node* newNode = new node(value);
    root = sortedInsert(root, newNode);
}

BinaryTree::node* BinaryTree::sortedInsert(node* root, node* newNode) {
    if (nullptr == root) {
        return newNode;
    }
    if (root -> data > newNode -> data) {
        root -> left = sortedInsert(root -> left, newNode);
    }
    else {
        root -> right = sortedInsert(root -> right, newNode);
    }
    return root;
}

/*   Balanced Insert   */

int BinaryTree::heightLeft(node* start) {
    if (nullptr == start) {
        return 0;
    }
    return heightLeft(start->left)+1;
}

int BinaryTree::heightRight(node* start) {
    if (nullptr == start) {
        return 0;
    }
    return heightRight(start->right)+1;
}


void BinaryTree::balancedInsert(int value) {
    node* newNode = new node(value);
    root = balancedInsert(root, newNode);
}

BinaryTree::node* BinaryTree::balancedInsert(node* root, node* newNode) {
    if (nullptr == root) {
        return newNode;
    }
    if ((heightLeft(root) > heightRight(root)) && (1 >= (heightLeft(root) - heightRight(root)))) {
        root -> right = balancedInsert(root->right, newNode);
    } else {
        root -> left = balancedInsert(root -> left, newNode);
    }
    return root;
}

/*   Find   */

bool BinaryTree::find(node* root, int value) {
    if (nullptr == root) {
        return false;
    } else if (root -> data == value) {
        return true;
    } else if (value <= root -> data) {
        return find(root -> left, value);
    } else {
        return find(root -> right, value);
    }
}

bool BinaryTree::find(int value) {
    return find(root, value);
}

/*   Print    */

void BinaryTree::travers(node* start) {
    if (nullptr == start) {
        return;
    }
    std::cout << start -> data << std::endl;
    travers(start -> left);
    travers(start -> right);
}

void BinaryTree::travers() {
    travers(root);
}

/*   Remove   */

void BinaryTree::remove(node* start) {
    if (nullptr == start) {
        return;
    }
    remove(start -> left);
    remove(start -> right);
    delete start;
}

/*   Get max   */

int BinaryTree::max(int left, int right) {
    return left > right ? left : right;
}

/*   Size   */

int BinaryTree::size(node *start) {
    if (nullptr == start) {
        return 0;
    }
    return size(start->left) + size(start->right) +1;
}

int BinaryTree::size() {
    return size(root);
}

/*   Height   */

int BinaryTree::height(node* start) {
    if (nullptr == start) {
        return 0;
    }
    return max(height(start->left), height(start->right)) +1;
}
int BinaryTree::height() {
    return height(root);
}
