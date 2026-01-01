#include <bits/stdc++.h>
using namespace std;

// Pass by reference using pointer
int changeByPointer(int *ptr)
{
    *ptr = 20;
}

int changeByAlias(int &b)
{
    b = 200;
}

int main()
{
    int a = 100;
    // changeByPointer(&a);

    changeByAlias(a);

    cout << a << endl;
    return 0;
}
