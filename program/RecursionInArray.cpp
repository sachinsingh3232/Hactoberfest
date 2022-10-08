#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size) {
    if(size<=1)
        return true;
    if(arr[0] > arr[1])
        return false;
    else
        return isSorted(arr+1, size-1);
}

int findSum(int arr[], int size) {
    if(size==0)
        return 0;
    return arr[0] + findSum(arr+1, size-1);
}

bool linearSearch(int arr[], int size, int key) {
    if(size==0)
        return false;
    if(arr[0]==key)
        return true;
    else
        return linearSearch(arr+1, size-1, key);
}

bool binarySearch(int arr[], int start, int end, int key) {
    int mid = start + (end-start)/2;
    if(start > end)
        return false;
    if(arr[mid] == key)
        return true;
    if(arr[mid]>key)
        return binarySearch(arr, start, mid-1, key);
    else
        return binarySearch(arr, mid+1, end, key);
}

int main() {
    int arr[10] = {2, 5, 8, 10, 12, 12, 15, 18, 20, 25};
    int size = 10;

    /*
    if(isSorted(arr, size))
        cout<<"Array is sorted";
    else
        cout<<"Array is not sorted";
    */

    //cout<<"Sum = "<<findSum(arr, size);

    /*
    int key = 80;
    if(linearSearch(arr, size, key))
        cout<<"Key is found in the array";
    else
        cout<<"Key is not found in the array";
    */

    /*
    int key = 15;
    if(binarySearch(arr, 0, size-1, key))
        cout<<"Key is found in the array";
    else
        cout<<"Key is not found in the array";
    */
    
    return 0;
}