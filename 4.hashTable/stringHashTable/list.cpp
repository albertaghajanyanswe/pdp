#include "list.hpp"
#include <iostream>

List::List():
	head(nullptr)
{}

List::List(const List& other)
   : head(nullptr)
{
	node* current = other.head;
	while (nullptr != current -> next) {
		pushFront(current -> key, current -> value);
        current = current->next;
	}
	pushFront(current -> key, current -> value);
}

List::~List() {
    clear();
}

/*   Clear list   */

void List::clear() {
    if(head == nullptr) {
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
}

/*   Print list   */

void List::printList() {
    int i = 0;
    node *curr = head;
    std::cout << "***** List *****" << std::endl;
    std::cout << "Key\tValue\n";
    while (curr != NULL) {
        std::cout << curr -> key  << "   ->   " << curr -> value << std::endl;
        curr = curr->next;
        ++i;
    }
}

/*   isEmpty()   */

bool List::isEmpty() {
    return nullptr == head;
}

/*  GetCount()   */

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

/*   PUSH-FRONT   */

bool List::pushFront(const std::string key, const int value) {
    node *n = new node(key, value);
    if (findKey(n->key, n->value)) {
        return false;
    }
    n -> next = head;
    head = n;
	return true;
}

/*  getValueByKey()    */

bool List::getValueByKey(std::string key, int& value) {
    if (nullptr == head) {
		std::cout << "\nMutqagrac Key-ov arjeq chka listum\n" << std::endl;
        return false;
    }
    if (head -> key == key) {
        value = head -> value;
		return true;
    }
    node *curr = head;
    while (nullptr != curr -> next) {
        if (curr -> next -> key == key) {
            value = curr -> next -> value;
			return true;
        }
        curr = curr -> next;
    }
    std::cout << "\nMutqagrac Key-ov arjeq chka listum\n" << std::endl;
    return false;
}

/*  getKeyByValue()   */

bool List::getKeyByValue(std::string& key, int value) {
    if (nullptr == head) {
        return false;
    }
    if (head -> value == value) {
        key = head -> key;
		return true;
    }
    node *curr = head;
    while (nullptr != curr -> next) {
        if (curr -> next -> value == value) {
            key = curr -> next -> key;
			return true;
        }
        curr = curr -> next;
    }
    return false;
}

/*   FindKey()   */
/* Override exiting value */

bool List::findKey(std::string& key, int& value) {
    if (head == NULL) {
        return false;
    }
    if (head -> key == key) {
        head -> value = value;
        return true;
    }
    node *curr = head;
    while (nullptr != curr -> next) {
        if (curr -> next -> key == key) {
            curr -> next -> value = value;
            return true;
        }
        curr = curr -> next;
    }
	return false;
}


bool List::deleteByKey(const std::string& delKey, int & value) {
    if (nullptr == head) {
        return false;
    }
    if (head -> key == delKey) {
		value = head -> value;
        node* h = head;
        head = head->next;
        delete h;
        return true;
    }
    node *curr = head;
    while (nullptr != curr -> next) {
        if (curr -> next -> key == delKey) {
			curr -> next -> value = value;
            node* n = curr -> next;
            curr -> next = n -> next;
            delete n;
            return true;
        }
        curr = curr -> next;
    }
	value = 0;
	return false;
}
