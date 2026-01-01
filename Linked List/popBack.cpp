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

    void pop_back()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No element is present to delete." << endl;
            return;
        }

        while (temp->nextPtr != tail)
        {
            temp = temp->nextPtr;
        }

        temp->nextPtr = NULL;
        delete tail;
        tail = temp;
    }

    void print_ll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->nextPtr;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.print_ll();

    ll.pop_back();

    ll.print_ll();
}