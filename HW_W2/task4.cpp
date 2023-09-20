#include <iostream>

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

struct Queue
{
    Node* head;
    Node* tail;
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int x)
    {
        Node* newNode = new Node(x);
        if(!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue()
    {
        if(!head)
        {
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    void display()
    {
        Node* current = head;
        while(current)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Queue q;
    for(int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;

        if(operation == "enqueue")
        {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if(operation == "dequeue")
        {
            q.dequeue();
        }
    }
    q.display();

    return 0;
}