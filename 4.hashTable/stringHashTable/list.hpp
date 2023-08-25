#ifndef LIST_H
#define LIST_H

#include <string>

class List {
public:
    List();
    List(const List& other);
    ~List();
    bool isEmpty();
    int getCount() const;

    bool getValueByKey(std::string key, int& value);
    bool getKeyByValue(std::string& key, int value);
    void printList();
    bool pushFront(const std::string key, const int value);
    void clear();
    bool deleteByKey(const std::string& delKey, int& value);
    struct node {
        node* next;
        std::string key;
        int value;
        node():
            key(""),
            value(0),
            next(nullptr)
        { }
        node(std::string key, int value):
            key(key),
            value(value),
            next(nullptr)
        { }
};
private:
    node *head;
	bool findKey(std::string& key, int& value);
};

#endif

