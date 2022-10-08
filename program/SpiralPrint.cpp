#include <iostream>
using namespace std;

int main() {
    int arr[100][100], row, col;
    cout<<"Enter the row and column size of the array: ";
    cin>>row>>col;

    cout<<"\nEnter the elements of the array: \n";
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin>>arr[i][j];
        }
    }

    int count=0;
    int total = row * col;

    int frow = 0;               // First Row
    int fcol = 0;               // First Coloumn
    int lrow = row-1;           // Last Row
    int lcol = col-1;           // Last Column

    while(count < total) {
        for(int i=fcol; i<=lcol; i++) {
            cout<<arr[frow][i]<<" ";
            count++;
        }
        frow++;

        for(int i=frow; i<=lrow; i++) {
            cout<<arr[i][lcol]<<" ";
            count++;
        }
        lcol--;

        for(int i=lcol; i>=fcol; i--) {
            cout<<arr[lrow][i]<<" ";
            count++;
        }
        lrow--;

        for(int i=lrow; i>=frow; i--) {
            cout<<arr[i][fcol]<<" ";
            count++;
        }
        fcol++;
    }

    return 0;
}