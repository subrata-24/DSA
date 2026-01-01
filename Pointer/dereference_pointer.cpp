#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int a; try this.
    int a = 10;
    int *ptr = &a;
    cout << *(&a) << endl;
    cout << *ptr << endl;

    int **ptrToptr = &ptr;
    cout << &ptr << endl;
    cout << ptrToptr << endl;

    cout << a << endl;
    cout << **ptrToptr << endl;
    return 0;
}
