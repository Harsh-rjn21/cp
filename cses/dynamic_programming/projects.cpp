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

int n;
vector<pair<pii, int>> arr;
int dp[200007];

int solve(int index)
{
    if (index == n)
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];
    int ans = 0;
    ans = max(ans, solve(index + 1));

    int day = arr[index].f.s + 1;
    pair<pii, int> s = {{day, 0}, 0};
    auto itr = lower_bound(arr.begin(), arr.end(), s);
    int i = itr - arr.begin();
    ans = max(ans, arr[index].s + solve(i));
    return dp[index] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp, -1, sizeof(dp));

    cin >> n;

    rep(i, 1, n)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pair<pii, int> h = {{x, y}, z};
        arr.pb(h);
    }

    sort(arr.begin(), arr.end());

    cout << solve(0) << "\n";

    return 0;
}