#include <bits/stdc++.h>
#define PB push_back
#define ll long long int
#define MP make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

// str.erase(1, 4);
// int B = b - '0' + 48;
long long int LargestSum(int a[], int n)
{
    int ans = arr[0], currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        ans = max(currentSum, ans);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}