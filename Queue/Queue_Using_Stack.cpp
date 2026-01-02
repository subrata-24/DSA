#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue() {}

    void push(int x)
    {
        while (!s1.empty())
        {
            int val = s1.top();
            s2.push(val);
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            int val = s2.top();
            s1.push(val);
            s2.pop();
        }
    }

    int pop()
    {
        int val = s1.top();
        s1.pop();
        return val;
    }

    int peek() { return s1.top(); }

    bool empty() { return s1.empty(); }
};

int main()
{
    MyQueue *obj = new MyQueue();
    // push
    obj->push(3);
    obj->push(4);
    obj->push(5);

    // pop->LIFO
    int rmv = obj->pop();
    cout << rmv << endl;

    // Top element
    int topper = obj->peek();
    cout << topper << endl;

    // Stack is empty or not
    bool isEmpty = obj->empty();
    cout << isEmpty << endl;
    return 0;
}
