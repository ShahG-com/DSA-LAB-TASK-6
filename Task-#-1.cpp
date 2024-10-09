#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert  node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printList();
    }

    // Insert  node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        printList();
    }

    // Insert  node at a specific position 
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
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;

        printList();
    }

    // Delete  node from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        printList();
    }

    // Delete node from the end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
        printList();
    }

    // Delete a node from a specific position 
    void deleteFromPosition(int position) {
        if (head == NULL || position <= 0) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        delete temp;
        printList();
    }

    // Function to print the current list
    void printList() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Current List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    cout<<" Inserting the Node at the Begining :"<<endl;
    dll.insertAtBeginning(10);
    cout<<"\nAfter inserting the Node at the End :"<<endl;
    dll.insertAtEnd(20);
    cout<<"\nAfter inserting the Node in the Middle :"<<endl;
    dll.insertAtPosition(15, 2);
    cout<<"\nDeleting the Node from the Begining :"<<endl;
    dll.deleteFromBeginning();
    cout<<"\nDeleting the Node from the End :"<<endl;
    dll.deleteFromEnd();
    cout<<"\nAfter the Deletion of Node :"<<endl;
    dll.deleteFromPosition(1);

    return 0;
}