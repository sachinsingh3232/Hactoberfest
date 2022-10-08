#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& mapping, int arr[10][10]) {
    return (x<0 || y<0 || x>=n || y>=n || mapping[x][y]==1) ? false : (arr[x][y]==1 ? true : false);
}

void findPaths(int arr[10][10], int n, int x, int y, vector<string>& solution, string output, vector<vector<int>>& mapping) {
    if(x==n-1 && y==n-1) {
        solution.push_back (output);
        return;
    }

    mapping[x][y] = 1;
    int newx, newy;

    // Checking for UP location
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, mapping, arr)) {
        output.push_back ('U');
        findPaths(arr, n, newx, newy, solution, output, mapping);
        output.pop_back();
    }

    // Checking for DOWN location
    newx = x+1;
    newy = y;
    if(isSafe(newx, newy, n, mapping, arr)) {
        output.push_back ('D');
        findPaths(arr, n, newx, newy, solution, output, mapping);
        output.pop_back();
    }

    // Checking for LEFT location
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, mapping, arr)) {
        output.push_back ('L');
        findPaths(arr, n, newx, newy, solution, output, mapping);
        output.pop_back();
    }

    // Checking for RIGHT location
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, mapping, arr)) {
        output.push_back ('R');
        findPaths(arr, n, newx, newy, solution, output, mapping);
        output.pop_back();
    }

    mapping[x][y] = 0;
}

int main() {
    int arr[10][10];
    int n;

    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"Enter the elements of matrix: ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> mapping;
    for(int i=0; i<n; i++) {
        vector<int> temp (n,0);
        mapping.push_back (temp);
    }

    vector<string> solution;
    string output = "";

    findPaths(arr, n, 0, 0, solution, output, mapping);

    for(int i=0; i<solution.size(); i++) {
        cout<<solution[i]<<endl;
    }

    return 0;
}