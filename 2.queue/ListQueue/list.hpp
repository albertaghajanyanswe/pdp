#ifndef LIST_H
#define LIST_H

class List {
public:
	List();
	List(const List& other);
	~List();
	bool isEmpty();
	int getCount() const;

	int retrieve(int index);

	void insert(int index, int item);
	void remove(int index);
	void sortedList();
	void printList();
private:

    struct node {
	node* next;
	int item;
	node():
		item(0),
		next(nullptr)
	{ }
    };
    node *head;
};
#endif
