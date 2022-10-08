#include <bits/stdc++.h>
using namespace std;

bool SearchMatrix(int arr[][100], int row, int col, int key) {
    int rowCount = 0;
    int colCount = col - 1;

    while((rowCount < row) && (colCount >= 0)) {
        int element = arr[rowCount][colCount];

        if(element == key) {
            return true;
        }

        if(element > key) {
            colCount--;
        }

        if(element < key) {
            rowCount++;
        }
    }

    return false;
}

int main() {
    int arr[100][100], row, col, key;
    cout<<"Enter the row and column size of the array: ";
    cin>>row>>col;

    cout<<"\nEnter the elements of the array: \n";
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"\nEnter the key to search: ";
    cin>>key;


    if(SearchMatrix(arr, row, col, key))
        cout<<endl<<key<<" is found in the matrix";
    else
        cout<<endl<<key<<" is not found in the matrix";

    return 0;
}