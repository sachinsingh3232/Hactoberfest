#include <iostream>
#include <conio.h>
using namespace std;

bool isSorted_logic1(int arr[], int n) {
    if(arr[n-1] >= arr[n-2] || n<=2) {
        return true;
    }

    if(arr[n-1] < arr[n-2]) {
        return false;
    }

    return isSorted_logic1(arr, n-1);
}

bool isSorted_logic2(int arr[], int n) {
    if(n<=1) {
        return true;
    }

    if(arr[0] > arr[1]) {
        return false;
    } else {
        return isSorted_logic2(arr+1, n-1);
    }
}

int main() {
    int arr[100], n;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    if(isSorted_logic1(arr, n)) {
        cout<<"\nSORTED ARRAY !!";
    } else {
        cout<<"\nUNSORTED ARRAY !!";
    }

    return 0;
}