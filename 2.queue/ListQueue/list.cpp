#include "list.hpp"
#include <iostream>

List::List():
	head(nullptr)
{}

List::List(const List& other)
   : head(nullptr)
{
    node* current = other.head;
    int i = 0;
    while (nullptr != current -> next) {
        insert(i, current -> item);
        current = current -> next;
        ++i;
    }
    insert(i, current -> item);
}

List::~List() {
	if(head == nullptr) {
			std::cout << "List is empty" << std::endl;
			return;
		}
		while(head -> next != nullptr) {
			node *temp = head;
			head = head->next;
			delete temp;
		}
		node *temp = head;
		head = nullptr;
		delete temp;
		std::cout << "List deleted" << std::endl;
}


bool List::isEmpty() {
	return 0 == getCount();
}


int List::getCount() const {
		if(nullptr == head) {
			return 0;
		}
		node *temp = head;
		int count = 1;
		while(temp->next != nullptr) {
			++count;
			temp=temp->next;
		}
		return count;
}

void List::sortedList() {
	if (1 >= this->getCount()) {
		return;
	}
	node* prev = head;
	node* next = head -> next;
    int count = 1 - (getCount()-1);
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < count; ++j) {
			if (prev -> item > next -> item) {
				node *temp = new node;
				temp->item = prev->item;
				prev->item = next -> item;
				next -> item = temp->item;
				prev = prev -> next;
				next = next -> next;
            }
        }
		prev = head;
		next = head -> next;
    }
	std::cout << "\nList sorted\n";
}

void List::insert(int index, int item) {
    node *n = new node();
    n-> item = item;
    if(nullptr == head) {
        if(0 == index) {
            head = n;
            std::cout << "\nAdded\n";
        } else {
            std::cout << "\nIncorrect index\n" << std::endl;
        }
    } else if (head -> next == nullptr) {
        if (0 == index) {
            n -> next = head;
            head = n;
            std::cout << "\nAdded\n";
        } else if (1 == index) {
            head -> next = n;
            std::cout << "\nAdded\n";
        }
        else {
            std::cout << "\nIncorrect index" << std::endl;
        }
    }
    else {
        if (0 == index) {
            node *temp = head;
            head = n;
            n -> next = temp;
            std::cout << "\nAdded\n";
        } else {
            node *curr = head;
            for(int i = 0; i < index - 2; i++) {
                if(curr -> next == nullptr) {
                    std::cout<<"\nIndex is incorrect. Will be added from end.\n" << std::endl;
                    break;
                }
                curr = curr -> next;
            }
            node *n = new node();
            n -> item = item;
            node *temp = curr ->next;
            curr -> next = n;
            n -> next = temp;
            std::cout << "\nAdded\n";
        }
    }
}

int List::retrieve(int index) {
    if (getCount() == 0) {
		std::cout << "List is empty\n";
        return -1;
    }
	if (index > getCount() || index < 0) {
		std::cout << "Incorrect index\n";
        return -1;
    }
    node* current = head;
    for (int i = 0; i < index; i++) {
        current = current-> next;
    }
	return current -> item;
}

void List::remove(int index)
{
	if (isEmpty() || index < 0 || index > getCount() - 1)
    {
		std::cout << "Incorrect index\n";
        return;
    }
    node* oldNode = nullptr;
    if (index == 0) {
        oldNode = head;
        head = head -> next;
    } else {
        node* current = head;
        for (int i = 0; i < index-1; i++) {
           current = current -> next;
        }
        oldNode = current->next;
        current -> next = oldNode -> next;
    }
    delete oldNode;
}

void List::printList() {
	int i = 0;
	node *curr = head;
	std::cout << "***** List *****" << std::endl;
	while (curr != NULL) {
		std::cout << i << " -> " << curr->item << std::endl;
		curr = curr->next;
		++i;
	}
}
