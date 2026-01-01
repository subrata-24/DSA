#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    // ptr++;//add sizeof(1) = 4 byte
    // ptr--;
    cout << &a << " " << ptr << endl;

    ptr = ptr + 4; // add sizeof(4) = 16 byte
    cout << &a << " " << ptr << endl;

    // Subtraction.(Addition is not possible)
    int *ptr1;
    int *ptr2 = ptr1 + 2;
    cout << ptr1 << " " << ptr2 << endl;
    cout << ptr2 - ptr1 << endl;

    // Comparison
    cout << (ptr1 < ptr2) << endl;
    cout << (ptr1 > ptr2) << endl;
    cout << (ptr1 == ptr2) << endl;
    cout << (ptr1 != ptr2) << endl;
    cout << (ptr1 <= ptr2) << endl;
    cout << (ptr1 >= ptr2) << endl;

    return 0;
}
