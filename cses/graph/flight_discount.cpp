#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

int visited[100007];
vector<pii> graph[100007],distances[100007];

void djikstra(int src){
    multiset<pair<int,pii>> bfs;
    bfs.insert({0,{0,src}});

    while(sz(bfs)){
        auto x = *(bfs.begin());
        bfs.erase(bfs.begin());
        int parent = x.s.s, maxi = x.s.f, dist = x.f;
        if(visited[parent]>=10)continue;
        visited[parent]++;
        for(auto i : graph[parent]){
            int child = i.f, wt = i.s;
            int maxi1 = wt>maxi ? wt : maxi;
            int dis = wt + dist;
            distances[child].pb({dis,maxi1});
            bfs.insert({dis,{maxi1,child}});
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while(t--){

        int n,m;
        cin >> n >> m;

        rep(i,1,m){
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].pb({b,c});
        }

        djikstra(1);
        int ans = LLONG_MAX;
        for(auto i : distances[n]){
            ans = min(ans,(i.f - ((i.s)-(i.s)/2)));
            // cout << i.f << " " << i.s << endl;
        }
        cout << ans << "\n";
    }

    return 0;}