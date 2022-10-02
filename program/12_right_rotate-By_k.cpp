#include <bits/stdc++.h>
#define PB push_back
#define ll long long int
#define MP make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

// str.erase(1, 4);
// int B = b - '0' + 48;
void printAfterRotatingBy_K(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            cout << a[n - k + i] << " ";
        }
        else
        {
            cout << a[n - k] << " ";
        }
        cout << endl;
    }
}
void rightRotateBy_1(int a[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
    }
}
void rightRotateBy_k(int a[], int n, int k)
{
    // 1 2 3 4 5
    // reverse last k elements let k=2;  1 2 3 5 4
    // reverse fisrt n-k elements 3 2 1 5 4
    // reverse whole array 4 5 1 2 3
    for (int i = n - k, j = n - 1; i < j; i++, j--)
    {
        swap(a[i], a[j]);
    }
    for (int i = 0, j = n - k - 1; i < j; i++, j--)
    {
        swap(a[i], a[j]);
    }
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        swap(a[i], a[j]);
    }
}
void RotateBY_k(int a[], int n, int k)
{
    vector<int> v;
    int c = 0;
    for (int i = n - k; c < k; i++)
    {
        v.PB(a[i]);
        c++;
    }
    c = 0;
    for (int i = 0; c < n - k; i++)
    {
        v.PB(a[i]);
        c++;
    }
    loop(i, 0, n)
    {
        a[i] = v[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    // rightRotateBy_k(a, n, k);
    RotateBY_k(a, n, k);
    loop(i, 0, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}