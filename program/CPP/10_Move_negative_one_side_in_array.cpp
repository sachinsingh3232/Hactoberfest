#include <bits/stdc++.h>
#define PB push_back
#define ll long long int
#define MP make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

// str.erase(1, 4);
// int B = b - '0' + 48;
void moveNeg(int a[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (a[high] < 0)
        {
            swap(a[high], a[low++]);
        }
        else
        {
            high--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    moveNeg(a, n);
    loop(i, 0, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}