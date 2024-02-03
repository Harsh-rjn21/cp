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

int visited[100007];
int n, m, k;
vector<pii> graph[100007];
int distances[100007];
deq done[100007];

void djikstra(int src)
{
    multiset<pii> bfs;
    bfs.insert({0, src});

    while (sz(bfs) != 0)
    {
        auto x = *(bfs.begin());
        bfs.erase(bfs.begin());
        int parent = x.s, dist = x.f;
        if (visited[parent] >= k)
            continue;
        visited[parent]++;
        for (auto i : graph[parent])
        {
            int child = i.f, wt = i.s;
            if (distances[child] > wt + dist)
            {
                distances[child] = wt + dist;
            }
                bfs.insert({wt + dist, child});
                done[child].pb(wt + dist);
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

        cin >> n >> m >> k;

        rep(i, 1, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].pb({b, c});
        }

        rep(i, 1, n)
        {
           distances[i] = 10000000000;
        }
        distances[1] = 0;
        djikstra(1);

        rep(i,1,n){
            sort(all(done[i]));
        }

        // rep(i, 1, n)
        // {
        //     cout << i << " ";
        //     for(auto j : done[i]) cout << j << " ";
        //     cout << "\n";
        // }

        rp(i,0,k){
            cout << done[n][i] << " ";
        }
    }

    return 0;
}