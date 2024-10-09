#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public :
    Node* head;
    DoublyLinkedList() {
        head = nullptr;
    }
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printList();
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        printList();
    }
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;

        printList();
    }
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;

        printList();
    }
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
        printList();
    }
    void deleteFromPosition(int position) {
        if (head == nullptr || position <= 0) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
        printList();
    }
    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Current List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Test deleting from an empty list
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteFromPosition(1);

    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtPosition(15, 2);

    // Test inserting at a position greater than the length of the list
    dll.insertAtPosition(25, 5); // Assuming the list has 3 elements

    // Test deleting all nodes one by one
    while (dll.head != nullptr) {
        dll.deleteFromBeginning();
    }

    // Try further deletions on an empty list
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteFromPosition(1);

    return 0;
}