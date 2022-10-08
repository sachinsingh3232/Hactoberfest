#include <bits/stdc++.h>
using namespace std;

void powerSet(vector<int> arr, vector<int> output, int index, vector<vector<int>>& solution) {
    if(index >= arr.size()) {
        solution.push_back (output);
        return;
    }

    // Excluding the element
    powerSet(arr, output, index+1, solution);

    // Including the element
    output.push_back (arr[index]);
    powerSet(arr, output, index+1, solution);
}

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        arr.push_back (x);
    }

    vector<vector<int>> solution;
    vector<int> output;
    int index = 0;

    powerSet(arr, output, index, solution);

    cout<<"\n\nAll the power sets are:\n";
    for(int i=0; i<solution.size(); i++) {
        cout<<"{ ";
        
        for(int j=0; j<solution[i].size(); j++) {
            cout<<solution[i][j]<<" ";
        }

        cout<<"}\n";
    }

    return 0;
}