// CS136 , Lab7 Circular Linked List
// Siavash Mehrabani, Anton Batac, Fernando Quijada

#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}    
};

template<typename T>
class CLinkedList {
private:
    Node<T>* head;
public:
    CLinkedList() : head(nullptr) {}
    void insertAtStart(T val){
        Node<T>* newNode = new Node<T>(val);
        if(head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself
        }
        else {
            Node<T>* last = head;
            while(last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            head = newNode;
            last->next = head;
        }
    }

    void insertAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if(head == nullptr) {
            head = newNode;
            head->next = head; // Point to head
        }
        else {
            Node<T>* last = head;
            while(last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
        }
    }

    void deleteByValue(T val) {
        if(head != nullptr) {
            Node<T>* current = head;
            Node<T>* prev = nullptr;
            while(current->data != val && current->next != head) {
                prev = current;
                current = current->next;
            }
            if (current->data == val) {
                if(current == head) {
                    Node<T>* last = head;
                    while(last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                }
                else 
                    prev->next = current->next;

                delete current;
            }
        }
    }

    void print() {
        if (head != nullptr) {
            Node<T>* current = head;
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);

            cout << endl;
        }
    }

    void splitCLinkedList (CLinkedList& list, int position, CLinkedList<T>& newList) {
        if (head == nullptr) {
            return;
        }
        Node<T>* current = head;
        int count = 1;

        while (count < position && current->next != head) {
            current = current->next;
            count++;
        }

        if (current->next == head) {
            return;
        }

        Node<T>* newHead = current->next;
        current->next = head;

        Node<T>* last = newHead;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newHead;
        newList.head = newHead;
    }
};

int main() {
    CLinkedList<int> list;
    CLinkedList<int> newList;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);


    cout << "CLinkedList: ";
    list.print();

    list.splitCLinkedList(list, 3, newList);

    cout << "First half: ";
    list.print();

    cout << "Second half: ";
    newList.print();
    
    return 0;
}