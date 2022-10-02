#include <iostream>
#include <vector>
using namespace std;

void answer(int n){
    string arr[10]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> v;
    while (n>0)
    {
        int dig= n%10;
        v.push_back(arr[dig]);
        n/=10;
    }
    for (int i = v.size()-1; i >=0; i--)
        cout<<v[i]<<endl;
}
int main()
{
    
    int d;
    cout<<"Enter the number: ";
    cin>>d;
    answer(d);
    return 0;
}