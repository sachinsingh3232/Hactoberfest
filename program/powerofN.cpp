#include <bits/stdc++.h>
using namespace std;

long long calcPower_1(int n, int p) {
    if(p==0) {
        return 1;
    }

    return n * calcPower_1(n, p-1);
}

// More optimized approach
long long calcPower_2(int n, int p) {
    if(p==0) {
        return 1;
    }

    if(p==1) {
        return n;
    }

    int ans = calcPower_2(n, p/2);
    
    return (p&1) ? (n * ans * ans) : (ans * ans);
}

int main() {
    int num, power;

    cout<<"Enter the number: ";
    cin>>num;

    cout<<"Enter the power: ";
    cin>>power;

    //int ans = calcPower_1(num, power);
    int ans = calcPower_2(num, power);

    cout<<"\n"<<num<<" to the power "<<power<<" is: "<<ans;
    return 0;
}