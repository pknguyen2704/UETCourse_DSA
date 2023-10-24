#include <iostream>

using namespace std;
struct Node {
    int value;
    Node* next;
    Node() {
        this->value = -1;
        this->next = NULL;
    }

    Node(int _value, Node* _next) {
        this->value = _value;
        this->next = _next;
    }
};

struct SLinkedList {
    Node* head;
    SLinkedList() {
        head = NULL;
    }

    void insert(int p, int value) {
        Node* newNode = new Node(value, NULL);
        if(p == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for(int i = 0; i < p - 1 && current != NULL; i++) {
                current = current->next;
            }
            if(current != NULL) {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
    void deleteNode(int p) {
        if(p == 0 && head != NULL) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        } else {
            Node* current = head;
            for(int i = 0; i < p - 1 && current != NULL; i++) {
                current = current->next;
            }
            if(current != NULL) {
                Node* tmp = current->next;
                current->next = tmp->next;
                delete tmp;
            }
        }
    }
    void printList(){
        Node* current = head;
        while(current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
    }
};
int main(){
    int n;
    cin >> n;
    SLinkedList list;
    for(int i = 0; i < n; i++) {
        int p, value;
        cin >> p >> value;
        list.insert(p, value);
    }
    list.deleteNode(2);
    list.printList();
    return 0;
}