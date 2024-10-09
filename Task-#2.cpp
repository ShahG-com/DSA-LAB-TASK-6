#include <iostream>
using namespace std;

struct Node {
int data;
Node* prev;
Node* next;
};

    void insertAtEnd (Node ** head, int newData) {
    Node* newNode = new Node () ;
    Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;

}
    while (last->next != NULL) {
    last = last->next;
}
    last->next = newNode;
    newNode->prev = last;
}

    void printForward (Node* node) {
    Node* last = NULL;
    cout << "Forward traversal: ";
    while (node != NULL) {
        cout << node->data << " -> ";
        last = node;
        node = node->next;
    }
    cout << "NULL" << endl;
    
    cout << "Backward traversal: ";
    while (last != NULL) {
        cout << last->data << " -> ";
        last = last->prev;
    }
    cout << "NULL" << endl;
}

int main (){
    Node* head = NULL;
    cout<<"\t\tTraversal Linkedlist Program by Shahzaib Adil "<<endl;

    insertAtEnd (&head, 10) ;
    insertAtEnd (&head, 20) ;
    insertAtEnd (&head, 30) ;
    insertAtEnd (&head, 40) ;
    insertAtEnd (&head, 50) ;
    // Print the list forward and backward
    printForward (head) ;
    return 0;
}