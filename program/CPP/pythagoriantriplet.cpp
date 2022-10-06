#include <iostream>
using namespace std;

bool pyth(int x, int y, int z)
{
    int m = max(x, max(y, z));
    int a, b;
    if (m == x)
    {
        a = y;
        b = z;
    }
    else if (m == y)
    {
        a = x;
        b = z;
    }
    else
    {
        a = x;
        b = y;
    }
    // or
    // int m = max(x, max(y, z));
    // int s=x*x + y*y + z*z - m*m;
    // if(m*m==s)
    // return true;
    // else
    // return false;
    if (m * m == a * a + b * b)
        return true;
    else
        return false;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (pyth(a, b, c))
        cout << "pythagorian triplet";
    else
        cout << "not a pythagorian triplet";
    return 0;
}