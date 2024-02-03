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

vector<pii> graph[100007];
int distances[100007],visited[100007];

void djikstra(int src){
    set<pii> bfs;
    distances[src] = 0;
    bfs.insert({0,src});

    while(bfs.size()!=0){
        pii x = *(bfs.begin());
        bfs.erase(bfs.begin());
        int dist = x.f,parent = x.s;
        if(visited[parent]==1)continue;
        visited[parent] = 1;
        for(auto i : graph[parent]){
            int child = i.s,wt=i.f;
            if((wt+dist)<distances[child]){
                distances[child] = wt+dist;
                bfs.insert({wt+dist,child});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        rep(i,1,m){
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].pb({c,b});
        }
        rep(i,0,n){
            distances[i] = LLONG_MAX;
        }

        djikstra(1);
        rep(i,1,n){
            cout << distances[i] << " ";
        }

    }

    return 0;}