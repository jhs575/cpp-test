#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    if (!head) {
        cout << endl;
        return;
    }
    Node* current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " ";
        current = current->next;
    }
    cout << endl;
}

Node* createLinkedList() {
    int value;
    cin >> value;
    
    if (value == -1) return nullptr; 
    
    Node* head = new Node(value); 
    Node* current = head;
    
    while (cin >> value && value != -1) {
        Node* newNode = new Node(value);
        current->next = newNode;
        current = newNode;
    }
    
    return head;
}

void removeDuplicates(Node* head) {
    if (!head) return;
    
    Node* current = head;
    while (current) {
        Node* prev = current;
        Node* temp = current->next;
        
        while (temp) {
            if (temp->data == current->data) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next; 
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {

    Node* head = createLinkedList();
    removeDuplicates(head);
    printList(head);
    

    return 0;
}