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

struct sSet {
    Node* head ;
    sSet() {
        head = NULL;
    }
    void insert(int x) {
        // if(head == NULL) {
        //     head->value = x;
        //     head->next = NULL;
        // } else {
            bool found = 0;
            Node* curr = head;
            while(curr != NULL) {
                if(curr->value == x) {
                    found = true;
                    break;
                } else {
                    curr = curr->next;
                }
            }
            if(found == true)  {
                return;
            } else {
                Node* newNode = new Node(x, NULL);
                newNode->next = head;
                head = newNode;
            }
        //}
    }
    void display() {
        Node* curr = head;
        while(curr != NULL) {
            cout << curr->value << " ";
            curr = curr->next;
        }
    }
};
int main() {
    int n;
    cin >> n;
    sSet set;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        set.insert(tmp);
    }
    set.display();
    return 0;
}