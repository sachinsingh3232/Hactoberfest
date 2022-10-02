/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
*/
#include <bits/stdc++.h>
#define PB push_back
#define ll long long int
#define MP make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

// str.erase(1, 4);
// int B = b - '0' + 48;
int duplicateNum(int a[], int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int cnt = 0;
        int mid = (low + high) / 2;
        loop(i, 0, n + 1)
        {
            if (a[i] <= mid)
            {
                cnt++;
            }
        }
        if (cnt <= mid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
s