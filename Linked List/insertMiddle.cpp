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

    void insert_middle(int val, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1)
        {
            push_front(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid position" << endl;
                return;
            }
            temp = temp->nextPtr;
        }

        newNode->nextPtr = temp->nextPtr;
        temp->nextPtr = newNode;
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

    ll.insert_middle(5, 3);
    ll.insert_middle(7, 6);

    ll.print_ll();
}