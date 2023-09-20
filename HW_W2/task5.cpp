#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val, Node* n = NULL)
    {
        data = val;
        next = n;
    }
};

struct Stack
{
    Node* top;
    Stack()
    {
        top = NULL;
    }

    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if(!top)
        {
            return;
        }
        Node* tmp = top;
        top= top->next;
        delete tmp;
    }
    void display()
    {
        vector <int> v;
        Node* current = top;
        while(current)
        {
            v.push_back(current->data);
            current = current->next;
        }
        for(int i = v.size()-1; i >= 0; i--)
            cout << v[i] << " ";
    }
};

int main()
{
    int n;
    cin >> n;

    Stack s;
    for(int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;

        if(operation == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(operation == "pop")
        {
            s.pop();
        }
    }
    s.display();

    return 0;
}