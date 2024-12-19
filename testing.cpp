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

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtIndex(Node*& head, int index) {
    if (!head) return;
    
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; current && i < index - 1; i++) {
        current = current->next;
    }

    if (!current || !current->next) return;

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int main() {
    int Q;
    cin >> Q;
    Node* head = nullptr;

    for (int i = 0; i < Q; i++) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            insertAtHead(head, V);
        } else if (X == 1) {
            insertAtTail(head, V);
        } else if (X == 2) {
            deleteAtIndex(head, V);
        }
        printList(head);
    }
    return 0;
}