#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    if(arr[n-1]==key) {
        return n-1;
    }

    if(n==1) {
        return -1;
    }

    return linearSearch(arr, n-1, key);
}

int main() {
    int arr[100], n, key;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the key to search for: ";
    cin>>key;

    int position = linearSearch(arr, n, key);

    if(position == -1) {
        cout<<"\nKey is not found in the array.";
    } else {
        cout<<"\nKey is found in the array at position : "<<position;
    }

    return 0;
}