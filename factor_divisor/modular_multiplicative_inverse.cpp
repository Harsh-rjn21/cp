/*
a^-1 =  a^(m-2) % m
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int power(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return (ans % mod);
}

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a = 48;

    int inverse = power(a, mod - 2) % mod;

    cout << inverse;

    int z = ((84 % mod) * 1LL * (inverse % mod)) % mod;

    cout << z;

    return 0;
}