#include <bits/stdc++.h>
using namespace std;

int arraySum(int arr[], int n) {
    if(n==1) {
        return arr[0];
    }

    if(n==0) {
        return 0;
    }

    //int ans = arr[0] + arr[1]; 
    return arr[n-1] + arraySum(arr,n-1);
}

int main() {
    int arr[100], n;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"\nSum of the elements of the given array is : "<<arraySum(arr,n);

    return 0;
}