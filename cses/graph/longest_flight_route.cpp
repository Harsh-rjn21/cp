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

int n, m, parent[100007], dp[100007], visited[100007];
deq graph[100007], graphr[100007];

void check(int src)
{
    for (auto i : graph[src])
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            check(i);
        }
    }
}

int dfs(int src)
{
    if (visited[src] == 0)
    {
        return LLONG_MIN;
    }
    if (src == 1)
    {
        return 0;
    }
    if (dp[src] != -1)
        return dp[src];
    int ans = 0;
    for (auto i : graphr[src])
    {
        int x = 1 + dfs(i);
        if (ans < x)
        {
            ans = x;
            parent[src] = i;
        }
    }
    return dp[src] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> n >> m;
    rep(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graphr[b].pb(a);
    }

    visited[1] = 1;
    check(1);

    if (visited[n] == 0)
    {
        cout << "IMPOSSIBLE\n";
        continue;
    }

    rep(i, 0, n)
    {
        dp[i] = -1;
    }

    int z = dfs(n);
    int x = n;
    deq ans;
    while (x != 1 && x != 0)
    {
        ans.pb(x);
        x = parent[x];
    }
    ans.pb(x);
    reverse(all(ans));
    cout << sz(ans) << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}