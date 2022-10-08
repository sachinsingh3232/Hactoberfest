#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int start, int end) {
    if(start > end) {
        return -1;
    }

    int mid = start + (end-start)/2;
    if(arr[mid]==key) {
        return mid;
    }

    if(arr[mid]>key) {
        return binarySearch(arr, key, start, mid-1);
    } else {
        return binarySearch(arr, key, mid+1, end);
    }
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

    int position = binarySearch(arr, key, 0, n-1);

    if(position == -1) {
        cout<<"\nKey is not found in the array.";
    } else {
        cout<<"\nKey is found in the array at position : "<<position;
    }

    return 0;
}