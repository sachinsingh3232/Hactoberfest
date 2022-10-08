#include <iostream>
using namespace std;

int SearchMatrix(int arr[][100], int row, int col, int key) {
    int start = 0;
    int end = (row*col) - 1;

    while(start <= end) {
        int mid = start + (end-start)/2;
        int i = mid / col;
        int j = mid % col;

        if(arr[i][j] == key) {
            return mid;
        }

        if(arr[i][j] > key) {
            end = mid - 1;
        }

        if(arr[i][j] < key) {
            start = mid + 1;
        }
    }

    return -1;
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

    int ans = SearchMatrix(arr, row, col, key);
    
    if(ans == -1)
        cout<<endl<<key<<" is not found in the matrix";
    else
        cout<<endl<<key<<" is found in the matrix at position ("<<ans/col<<","<<ans%col<<")";

    return 0;
}