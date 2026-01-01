#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *nextPtr;

    Node(int val)
    {
        data = val;
        nextPtr = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->nextPtr = head;
            head = newNode;
        }
    }
};

int main()
{
    List ll;
}