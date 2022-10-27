#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout << "enter the size of array: ";
    cin >> size;
    int arr[size];
    // taking input of values of array
    for (int i = 0; i <size; i++)
    {
        cout << "enter the " << i + 1<< " element of array: ";
        cin >> arr[i];
    }
    // display of input array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // swaping alternate element of array
    for (int i = 0; i < size - 1; i = i + 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    // display of swaped array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
