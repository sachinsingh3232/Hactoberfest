#include <bits/stdc++.h>
using namespace std;
void insertionSort(int a[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (key < a[j] && j > -1)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int size;
    cout << "enter size of array";
    cin >> size;
    int arr[size];
    cout << "enter elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}
