#include <iostream>

using namespace std;
struct Node {
    int value;
    Node* next;
    Node(int _value, Node* _next) {
        this->value = _value;
        this->next = _next;
    }
};

struct Queue {
    Node* head;
    Node* tail;

    Queue() {
        head = NULL;
        tail = NULL;
    }
    void enqueue(int value) {
        Node* newNode = new Node(value, NULL);
        if(tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue() {
        if(head == NULL) {
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    void display() {
        Node* current = head;
        while(current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        q.enqueue(tmp);
    }
    q.dequeue();
    q.display();
    return 0;
}