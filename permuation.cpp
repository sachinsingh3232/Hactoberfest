// this code help to find total permutation of string
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int permute(string str, string str2, int k)
{
    if (str.size() == 0)
    {
        k++;
        cout<<k<<"\t";
        cout << str2 << endl;
        return k;
    }
    int i=0;
    while(i < str.size())
    {
      k= permute(str.substr(1), str2 + str[0], k);
        rotate(str.begin(), str.begin() + 1, str.end());
        i++;
    }
      return k;
}
int main()
{
    string str;
    cout<<"Enter string to find its permutation\n";
    cin>>str;
    cout<<"\n";
   int k= permute(str, "", 0);
   cout<<"Total number of permutation: "<<k;
    return 0;
}