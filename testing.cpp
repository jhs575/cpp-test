#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

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
int findIndex(Node* head, int X) {
    int index = 0;
    Node* current = head;
    
    while (current) {
        if (current->data == X) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node* head = createLinkedList();
        int X;
        cin >> X;
        cout << findIndex(head, X) << endl;
    }
    return 0;
}