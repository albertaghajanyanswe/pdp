#ifndef DEQUE_H
#define DEQUE_H

class Deque {
public:
    Deque();
    Deque(const Deque& orig);
    ~Deque();
    int& operator[](int const number);
    void push_front(const int & addData);
    void push_back(const int & addData);
    void pop_front();
    void pop_back();
    void pop_byData(const int & delData);
    bool empty() const;
    int count() const;
    void insert(int index, int item);
    void printDeque();
    void clear();
private:
    struct node {
        int item;
        node* next;
        node* prev;
        node():
            item(0),
            next(nullptr),
            prev(nullptr)
        { }
        node(int item, node* next = nullptr, node* prev = nullptr)
            : item(item),
              next(next),
              prev(prev)
        { }
    };

    node* head;
    node* tail;

};

#endif /* DEQUE_H */
