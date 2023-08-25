#include "deque.hpp"
#include <iostream>


Deque::Deque():
    head(nullptr),
    tail(nullptr)
{ }

Deque::Deque(const Deque& other)
   : head(nullptr),
     tail(nullptr)
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

/* Operator [] */

int & Deque::operator[](int const number) {
    int count1 = count();
    std::cout << std::endl;
    if(number >= count1 || number < 0) {
        int *a = nullptr;
        std::cout << "Incorrect index" << std::endl;
        return *a;
    }
    node *temp = head;
    for(int i = 0; i < number; i++){
        temp = temp -> next;
    }
    std::cout << std::endl << number << " -> " << temp -> item << std::endl;
    return temp -> item;
}

/*   PUSH-FRONT   */

void Deque::push_front(const int& item) {
    node* newHead = new node(item);
    if (empty()) {
        head = tail = newHead;
    } else {
        newHead -> next = head;
        head -> prev = newHead;
        head = newHead;
    }
}

/*   PUSH-BACK   */

void Deque::push_back(const int& item) {
    node* newTail = new node(item);
    if (empty()) {
        head = tail = newTail;
    }
    else {
        tail -> next = newTail;
        newTail -> prev = tail;
        tail = newTail;
    }
}

/*   POP-FRONT   */

void Deque::pop_front()  {
    if(nullptr == head) {
        std::cout << "Deque is empty!!!" << std::endl;
        return;
    }
    node* oldHead = head;
    if (head == tail) {
       head = tail =  nullptr;
    } else {
        head = head -> next;
        head -> prev = nullptr;
    }
    delete oldHead;
}

/*   POP-BACK   */

void Deque::pop_back() {
    if(nullptr == head) {
        std::cout << "Deque is empty!!!" << std::endl;
        return;
    }
    node* oldTail = tail;
    if (nullptr != tail -> prev) {
        tail = tail -> prev;
        tail -> next = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete oldTail;
};

/*   POP-BY-DATA   */

void Deque::pop_byData(const int & delData) {
    if (nullptr == head) {
        std::cout << "\nDeque is empty\n";
        return;
    }
    if (head -> item == delData) {
        node* h = head;
        head = head->next;
        delete h;
        std::cout << std::endl << delData << " value deleted\n";
        return;
    }
    node *curr = head;
    while (nullptr != curr -> next) {
        if (curr -> next -> item == delData) {
            node* n = curr -> next;
            curr -> next = n -> next;
            delete n;
            std::cout << std::endl << delData << " value deleted\n";
            return;
        }
        curr = curr -> next;
    }
    std::cout << "\nValue not found in deque\n" << std::endl;
}

/*    EMPTY   */

bool Deque::empty() const {
    return nullptr == head;
}

/*   COUNT   */

int Deque::count() const {
    if(nullptr == head) {
        std::cout << "\nDeque is empty\n";
        return 0;
    } else {
        node *temp = head;
        int count = 1;
        while(nullptr != temp -> next) {
            ++count;
            temp = temp -> next;
        }
        return count;
    }
}

/*   INSERT   */

void Deque::insert(int index, int item) {
    node *n = new node();
    n -> item = item;
    if(nullptr == head) {
        if(0 == index) {
            head = n;
            std::cout << "\nAdded\n";
        } else {
            std::cout << "\nIncorrect index\n" << std::endl;
        }
    } else if (nullptr == head -> next) {
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
            for(int i = 0; i < index - 1; i++) {
                if(curr -> next == nullptr) {
                    std::cout<<"\nIndex is invalid. Wiil be added from!!!\n" << std::endl;
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

void Deque::clear() {
    if(head == nullptr) {
        std::cout << "Deque is empty" << std::endl;
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
    std::cout << "Deque deleted" << std::endl;
}

void Deque::printDeque() {
    int i = 0;
    node *curr = head;
    std::cout << "***** List 1 *****" << std::endl;
    while (nullptr != curr) {
        std::cout << i << " -> " << curr -> item << std::endl;
        curr = curr->next;
        ++i;
    }
}

/*   Destructor   */

Deque::~Deque() {
    clear();
}
