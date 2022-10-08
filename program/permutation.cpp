#include <bits/stdc++.h>
using namespace std;

void findPermutation(vector<int>& arr, int index, vector<vector<int>>& solution) {
    if(index >= arr.size()) {
        solution.push_back (arr);
        return;
    }

    for(int i=index; i<arr.size(); i++) {
        swap(arr[index], arr[i]);
        findPermutation(arr, index+1, solution);
        swap(arr[index], arr[i]);
    }
}

int main() {
    int n;
    vector<int> arr;
    vector<vector<int>> solution;
    int index = 0;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        arr.push_back (x);
    }

    findPermutation(arr, index, solution);
    sort(solution.begin(), solution.end());

    cout<<"\n\nThe permutation of entered array:\n";
    for(int i=0; i<solution.size(); i++) {
        cout<<"For i = "<<i<<"          ->       ";
        for(int j=0; j<solution[i].size(); j++) {
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}