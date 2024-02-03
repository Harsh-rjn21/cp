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
    int ans1 = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans1 = (ans1 % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return ans1 % mod;
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

    int t = 1;
    // cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int a[n + 2] = {0};

        rep(i, 1, n)
        {
            cin >> a[i];
        }

        // SECOND METHOD
        // COMPARING END POINTS OF SUBARRAY
        // FOR ANY END POINT k
        // max subarray sum ke contendor for end point i = k
        // 1) Kuchh bhi na ho
        // 2) Ya vo akela aaye
        // 3) (k-1) tak ka max sum + kth element

        int dp[n + 1] = {0};
        dp[1] = max(dp[1], a[1]);

        rep(i, 2, n)
        {
            dp[i] = max(dp[i], a[i]);
            dp[i] = max(dp[i], dp[i - 1] + a[i]);
        }

        int ans2 = dp[1];
        rep(i, 1, n)
        {
            ans2 = max(ans2, dp[i]);
        }

        cout << ans2 << endl;

        rep(i, 1, n) cout << dp[i] << " ";
        cout << "\n";
    }

    return 0;
}