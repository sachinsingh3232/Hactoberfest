#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    if(n <= 1) {
        return;
    }

    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, n-1);
}

int main() {
    int arr[100], n;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    bubbleSort(arr, n);

    cout<<"\nThe sorted array is: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}