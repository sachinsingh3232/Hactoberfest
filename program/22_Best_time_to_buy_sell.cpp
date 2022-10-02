/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock
and choosing a different day in the future to sell that stock.

Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell
*/
#include <bits/stdc++.h>
#define PB push_back
#define ll long long int
#define MP make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int i = 0, j = 1, max_Profit = 0;
    while (i < n && j < n)
    {
        if (prices[j] >= prices[i])
        {
            int sub = prices[j] - prices[i];
            max_Profit = max(max_Profit, sub);
            j++;
        }
        else
        {
            i = j;
            j = i + 1;
        }
    }
    return max_Profit;
}

// str.erase(1, 4);
// int B = b - '0' + 48;
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