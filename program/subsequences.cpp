#include <bits/stdc++.h>
using namespace std;

void allSubsequences(string str, string output, int index, vector<string>& solution) {
    if(index >= str.length()) {
        if(output != "") {
            solution.push_back (output);
        }
        return;
    }

    // Excluding the character
    allSubsequences(str, output, index+1, solution);

    // Including the character
    output.push_back (str[index]);
    allSubsequences(str, output, index+1, solution);
}

int main() {
    string str;
    cout<<"Enter the string: ";
    cin>>str;

    vector<string> solution;
    string output;
    int index = 0;

    allSubsequences(str, output, index, solution);

    sort(solution.begin(), solution.end());

    cout<<"\n\nAll the subsequences are:\n";
    for(int i=0; i<solution.size(); i++) {
        cout<<"\""<<solution[i]<<"\"\n";
    }

    return 0;
}