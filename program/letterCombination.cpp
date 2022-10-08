#include <bits/stdc++.h>
using namespace std;

void letterCombinations(string digits, string output, int index, vector<string>& combinations, string mapping[]) {
    if(index >= digits.length()) {
        combinations.push_back (output);
        return;
    }

    int number = digits[index] - 48;
    string value = mapping[number];

    for(int i=0; i<value.length(); i++) {
        output.push_back (value[i]);
        letterCombinations(digits, output, index+1, combinations, mapping);
        output.pop_back();
    }
}

int main() {
    string digits;
    cout<<"Enter the string: ";
    cin>>digits;

    vector<string> combinations;
    string output = "";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if(digits.length() > 0) {
        letterCombinations(digits, output, index, combinations, mapping);
    }
    
    cout<<"All the possible combinations are:\n";
    for(int i=0; i<combinations.size(); i++) {
        cout<<combinations[i]<<endl;
    }

    return 0;
}