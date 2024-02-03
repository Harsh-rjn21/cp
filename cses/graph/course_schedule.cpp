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

deq graph[100007];
deq ans;
int visited1[100007], stk[100007], visited2[100007];
int n, m;
bool cycle = false;

void cycle_detect(int src)
{
    stk[src] = 1;
    for (auto i : graph[src])
    {
        if (visited2[i] == 1 && stk[i] == 1)
        {
            cycle = true;
        }
        if (visited2[i] == 0)
        {
            visited2[i] = 1;
            cycle_detect(i);
        }
    }
    stk[src] = 0;
}

void solve(int src)
{
    for (auto i : graph[src])
    {
        if (visited1[i] == 0)
        {
            visited1[i] = 1;
            solve(i);
        }
    }
    ans.pb(src);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    cin >> n >> m;

    bool start[n + 1];

    rep(i, 1, n)
    {
        start[i] = true;
    }

    rep(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph2[b].pb(a);
        start[b] = false;
    }

    rep(i, 1, n)
    {
        if (visited2[i] == 0)
        {
            visited2[i] = 1;
            cycle_detect(i);
        }
    }

    if (cycle)
    {
        cout << "IMPOSSIBLE\n";
        continue;
    }

    rep(i, 1, n)
    {
        if (start[i] && visited1[i] == 0)
        {
            solve(i);
        }
    }

    reverse(all(ans));

    for (auto i : ans)
    {
        cout << i << " ";
    }
    
    return 0;
}