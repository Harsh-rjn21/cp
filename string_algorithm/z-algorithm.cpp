#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod)
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
    return ans % mod;
}

ll modInverse(ll n, ll mod)
{
    return power(n, mod - 2, mod) % mod;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    string a;
    cin >> a;

    int n = a.size();

    int z[n];
    z[0] = 0;

    int i1 = 0, i2 = 0;
    bool h = false;

    rp(i, 1, n)
    {
        if (i >= i2)
            h = false;
        int l = i - i1;
        if (h && z[l] + i < i2)
        {
            z[i] = z[l];
            continue;
        }
        else if (h)
        {
            int x = 0;
            int k = i2 - i, j = i2;
            while (j < n && a[j] == a[k])
            {
                ++j;
                ++x;
                ++k;
            }
            z[i] = i2 - i + x;
            i2 = j;
            i1 = i;
        }
        else
        {
            int x = 0;
            int j = i, k = 0;
            while (j < n && a[j] == a[k])
            {
                ++j;
                ++k;
                ++x;
            }
            z[i] = x;
            if (x != 0)
            {
                h = true;
                i1 = i;
                i2 = j;
            }
        }
    }

    rp(i,0,n)cout << z[i] << " ";

    return 0;
}