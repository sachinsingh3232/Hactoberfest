#include <bits/stdc++.h>
#define PB push_back
#define ll long long int
#define MP make_pair
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

// str.erase(1, 4);
// int B = b - '0' + 48;

/*<------------------Solution1- count 0s,1s,2s and put them in an array--------------->*/
/*<------------------------------------Solution2------------------------------------------------------->*/
void sort012(int a[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[low++], a[mid++]);
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high--]);
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
    sort012(a, n);
    loop(i, 0, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}