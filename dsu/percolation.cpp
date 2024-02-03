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

pii parent[100][100];
int Size[100][100];
int a[100][100];
void make(int n, int m)
{
    parent[n][m] = {n, m};
    Size[n][m] = 1;
}

pii find(int n, int m)
{
    pii z = {n, m};
    if (parent[n][m].f == n && parent[n][m].s == m)
    {
        return {n, m};
    }
    return parent[n][m] = find(parent[n][m].f, parent[n][m].s);
}

void Union(pii a, pii b)
{
    pii x = find(a.f, a.s);
    pii y = find(b.f, b.s);
    if (x != y)
    {
        if (Size[x.f][x.s] >= Size[y.f][y.s])
        {
            swap(x, y);
        }
        Size[y.f][y.s] += Size[x.f][y.s];
        parent[x.f][x.s] = y;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            cin >> a[i][j];
        }
    }

    rep(i, 0, n + 1)
    {
        rep(j, 0, n + 1)
        {
            make(i, j);
        }
    }

    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            if (a[i][j] == 1)
            {
                if (i == 1 && a[i][j] == 1)
                {
                    Union({0, 0}, {i, j});
                }
                if (i == n && a[i][j] == 1)
                {
                    Union({n + 1, n + 1}, {i, j});
                }
                if (i - 1 >= 1 && a[i - 1][j] == 1)
                {
                    Union({i - 1, j}, {i, j});
                }
                if (i + 1 <= (n) && a[i + 1][j] == 1)
                {
                    Union({i, j}, {i + 1, j});
                }
                if (j - 1 >= 1 && a[i][j - 1] == 1)
                {
                    Union({i, j - 1}, {i, j});
                }
                if (j + 1 <= n && a[i][j + 1] == 1)
                {
                    Union({i, j + 1}, {i, j});
                }
            }
        }
    }

    (find(0,0)==find(n+1,n+1)) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}