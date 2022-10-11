/*program*/
#include <bits/stdc++.h>
using namespace std;
long long power(long long int N, long long int R)
{
    if (R == 1)
        return N;
    long long int x = power(N, R / 2), m = 1000000007;
    if (R % 2 == 0)
    {
        return ((x % m * x) % m) % m;
    }
    else
    {
        return ((x % m * N) % m * x) % m;
    }
}

int main()
{
    long long int n, r;
    cin >> n;
    cin >> r;

    long long int c = power(n, r);
    cout << c << endl;

    return 0;
}