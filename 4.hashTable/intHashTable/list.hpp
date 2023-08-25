#ifndef LIST_H
#define LIST_H

class List {
public:
    List();
    List(const List& other);
    ~List();
    bool isEmpty();
    int getCount() const;

    bool getValueByKey(int key, int& value);
    bool getKeyByValue(int& key, int value);
    void printList();
    bool pushFront(const int key, const int value);
    void clear();
    bool deleteByKey(const int & delKey, int& value);
    struct node {
        node* next;
        int key;
        int value;
        node():
            key(0),
            value(0),
            next(nullptr)
        { }
        node(int key, int value):
            key(key),
            value(value),
            next(nullptr)
        { }
};
private:
    node *head;
	bool findKey(int& key, int& value);
};

#endif

