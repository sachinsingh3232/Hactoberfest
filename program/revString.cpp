#include <bits/stdc++.h>
using namespace std;

string ans;
void revString_1(string str, int size) {
    if(size==0) {
        return;
    }

    ans.push_back (str[size-1]);

    revString_1(str, size-1);
}

void revString_2(string &str, int start, int end) {
    if(start>end) {
        return;
    }

    swap(str[start], str[end]);
    revString_2(str, start+1, end-1);
}

void revString_3(string &str, int index) {
    if(index > str.length()/2-1) {
        return;
    }

    swap(str[index], str[str.length()-1-index]);
    revString_3(str, index+1);
}

int main() {
    string str;
    cout<<"Enter the string: ";
    cin>>str;

    //revString_1(str, str.length());
    //revString_2(str, 0, str.length()-1);
    revString_3(str, 0);

    cout<<"\nReverse of the given string is: "<<str;
    return 0;
}