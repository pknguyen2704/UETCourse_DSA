#include <iostream>

using namespace std;

struct Node
{
    int element;
    Node* next;

    Node()
    {
        element = 0;
        next = NULL;
    }
    Node(int e, Node* n = NULL)
    {
        element = e;
        next = n;       
    }
};

struct LinkedList
{
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void insert(int p, int x)
    {
        Node* newNode = new Node(x, NULL);
        if(p == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* current = head;
            for(int i = 0; i < p-1 && current != NULL; i++)
            {
                current = current->next;
            }
            if(current != NULL)
            {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
    void deleteNode(int p)
    {

        if(p == 0)
        {
            if(head != NULL)
            {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        else
        {
            Node* current = head;
            for(int i = 0; i < p-1 && current != NULL; i++)
            {
                current = current->next;
            }
            if(current != NULL && current->next != NULL)
            {
                Node* tmp = current->next;
                current->next = tmp->next;
                delete tmp;
            }
        }
    }
    void printList()
    {
        Node* current = head;
        while(current != NULL)
        {
            cout << current->element << " ";
            current = current->next;
        }
    }
};

int main()
{
    int n;  
    cin >> n;
    LinkedList linkedList;

    for(int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;

        if(operation == "insert")
        {
            int p, x;
            cin >> p >> x;
            linkedList.insert(p,x);
        }
        if(operation == "delete")
        {
            int p;
            cin >> p;
            linkedList.deleteNode(p);
        }
    }
    linkedList.printList();

    return 0;
}