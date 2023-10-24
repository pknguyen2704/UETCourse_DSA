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

struct Stack {
    Node* top;
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x, NULL);
            newNode->next = top;
            top = newNode;
    }

    void pop() {
        if(top == NULL) {
            return;
        } else {
            Node* tmp = top;
            top = top->next;
            delete tmp;
        }
    }
};

int main() {
    int n;
    cin >> n;
}