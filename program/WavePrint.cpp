#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100][100], r, c;
    cout<<"\nEnter the row and column of array: ";
    cin>>r>>c;

    cout<<"\nEnter the elements of the array: ";
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"\nDry run: ";
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout<<arr[i][j]<<" ";
        }
    }

    cout<<"\nThe array in wave format: ";
    for(int i=0; i<c; i++) {
        if(col&1) {
            for(int j=r-1; j>=0; j++) {
                cout<<arr[j][i]<<" ";
            }
        } else {
            for(int j=0; j<r; j--) {
                cout<<arr[j][i]<<" ";
            }
        }
    }

    return 0;
}