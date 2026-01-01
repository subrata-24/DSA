#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    int *ptr = &a;
    int **ptrToptr = &ptr;
    cout << &ptr << endl;
    cout << ptrToptr << endl;
    return 0;
}
