#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int val, Node* prev, Node* next)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

struct DoublyLinkedList
{
    Node* head;
    Node* tail;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val, NULL, NULL);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    int count_triplets()
    {
        int count = 0;
        Node* current = head;
        if(!current || !current->next || !current->next->next)
        {
            return count;
        }

        while(current->next->next)
        {
            int tripletSum = current->data + current->next->data + current->next->next->data;
            if(tripletSum == 0)
            {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    DoublyLinkedList dll;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dll.insert(num);
    }

    int result = dll.count_triplets();
    cout << result;

    return 0;
}