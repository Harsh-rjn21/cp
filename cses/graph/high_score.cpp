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

int distances[2507], parent[2507], visited1[2507], visited2[2507];
vector<int> graph1[2507];
vector<int> graph2[2507];

void dfs1(int src)
{
    for (auto i : graph1[src])
    {
        if (visited1[i] == 0)
        {
            visited1[i] = 1;
            dfs1(i);
        }
    }
}
void dfs2(int src)
{
    for (auto i : graph2[src])
    {
        if (visited2[i] == 0)
        {
            visited2[i] = 1;
            dfs2(i);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        rep(i, 1, n)
        {
            distances[i] = -1000000000000;
        }

        vector<pair<pii, int>> edges;

        rep(i, 1, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges.pb({{a, b}, c});
            graph1[a].pb(b);
            graph2[b].pb(a);
        }

        visited1[1] = 1;
        dfs1(1);
        visited2[n] = 1;
        dfs2(n);

        distances[1] = 0;

        int Start;
        int ans[n + 1] = {0};

        rep(e, 1, 2 * n)
        {
            Start = 0;
            for (auto i : edges)
            {
                if (distances[i.f.s] < i.s + distances[i.f.f])
                {
                    parent[i.f.s] = i.f.f;
                    if(e==n){
                        Start = i.f.s;
                        if(visited1[Start]==1 && visited2[Start]==1){
                            cout << "-1\n";
                            return 0;
                        }
                        }
                    distances[i.f.s] = i.s + distances[i.f.f];
                }
            }
            if (e == n - 1)
            {
                rep(i, 1, n)
                {
                    ans[i] = distances[i];
                }
            }
        }

        rep(i, 1, n) Start = parent[Start];
        // cout << Start << " " << visited1[Start] << " " << visited2[Start] << "\n";
        if (Start == 0)
        {
            cout << distances[n] << "\n";
            continue;
        }

        if (visited1[Start] == 1 && visited2[Start] == 1)
        {
            cout << "-1\n";
        }
        else
        {
            cout << distances[n] << "\n";
        }
    }

    return 0;
}