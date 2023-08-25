#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree& orig);
    virtual ~BinaryTree();

    bool isEmpty();
    int size();
    int height();
    void insert(int value);
    void travers();
    bool find(int value);
    void balancedInsert(int value);

private:
    struct node {
        int data;
        node* left;
        node* right;
        node(int value)
            :data (value),
             left(nullptr),
             right(nullptr)
        { };
    };
    node* root;
    node* copyTree(node* other);
    node* sortedInsert(node* root, node* newNode);
    void travers(node* start);
    bool find(node* root, int value);
    int size(node *start);
    int height(node* start);
    int max(int left, int right);
    void remove(node* start);
    int heightLeft(node* start);
    int heightRight(node* start);
    node* balancedInsert(node* root, node* newNode);
};


#endif /* BINARYTREE_H */
