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

int distances[2507], parent[2507];

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

        vector<pair<int, pii>> edges;

        rep(i, 1, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges.pb({c, {a, b}});
        }

        rep(i, 1, n)
        {
            distances[i] = 1000000000000;
        }

        distances[1] = 0;

        int Start;

        rep(i, 1, n)
        {
            Start = 0;
            for (auto e : edges)
            {
                if (distances[e.s.s] > e.f + distances[e.s.f])
                {
                    Start = e.s.s;
                    distances[e.s.s] = e.f + distances[e.s.f];
                    parent[e.s.s] = e.s.f;
                }
            }
        }

        if (Start == 0)
        {
            cout << "NO\n";
            continue;
        }

        rep(i, 1, n) Start = parent[Start];

        cout << "YES"
             << "\n";

        deq cycle;
        int x = Start;

        cycle.pb(x);

        while (x != Start || cycle.size() == 1)
        {
            x = parent[x];
            cycle.pb(x);
        }
        reverse(all(cycle));
        for (auto i : cycle)
            cout << i << " ";
    }

    return 0;
}