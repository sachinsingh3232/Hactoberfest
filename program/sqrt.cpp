#include <bits/stdc++.h>
using namespace std;

int sqRoot(int n, int start, int end) {
    // Base Case
    if(start>end)
        return 0;
    
    int mid = start + (end-start)/2;
    long long int square = mid*mid;

    // True Condition
    if(square == n)
        return mid;
    
    int ans;
    if(square < n) {
        // Lowest Possible SQRT
        ans = mid;
        int temp = sqRoot(n, mid+1, end);
        if(temp)
            ans = temp;
    } else
        ans = sqRoot(n, start, mid-1);
    return ans;
}

int main() {
    int num;
    cin>>num;
    cout<<"Square root : "<<sqRoot(num, 1, num/2);
    return 0;
}