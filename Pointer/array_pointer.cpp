#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    cout << &arr[0] << endl;
    cout << arr << endl;

    cout << *(arr + 2) << endl; // print the number of 3rd memory block

    // This is wrong.Because arr is a constant pointer which memory address can not be changed.
    //  int a = 10;
    //  arr = &a;
    return 0;
}
