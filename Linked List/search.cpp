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

    int search(int val)
    {
        Node *temp = head;
        int idx = 1;
        while (temp != NULL)
        {
            if (temp->data == val)
                return idx;
            temp = temp->nextPtr;
            idx++;
        }

        return -1;
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
    ll.push_front(8);

    ll.print_ll();

    int idx = ll.search(2);
    if (idx < 0)
        cout << "This value is not present" << endl;
    else
        cout << "The index number is " << idx << endl;
}