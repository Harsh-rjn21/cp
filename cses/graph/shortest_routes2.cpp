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

vector<pii> graph[507];
int levels[507][507],visited[507][507],distances[507][507];
int n,m,q;

void djikstra(int src){
    set<pii> bfs;
    bfs.insert({0,src});
    levels[src][src] = 0;
    while(sz(bfs)!=0){
        pii x = *(bfs.begin());
        int parent = x.s;
        bfs.erase(bfs.begin());
        if(visited[src][parent]==1)continue;
        visited[src][parent] = 1;
        for(auto i : graph[parent]){
            int child = i.f, dist = i.s;
            if(levels[src][child]>dist+levels[src][parent]){
                levels[src][child] = dist+levels[src][parent];
                bfs.insert({levels[src][child],child});
            }
        }
    }
    rep(i,1,n){
        if(levels[src][i]==LLONG_MAX){
            levels[src][i] = -1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while(t--){

        cin >> n >> m >> q;
        rep(i,0,n){
            rep(j,0,n){
                levels[i][j] = LLONG_MAX;
                distances[i][j] = LLONG_MAX;
            }
        }

        rp(i,0,m){
            int a,b,c;
            cin >> a >> b >> c;
            distances[a][b] = min(c,distances[a][b]);
            distances[b][a] = min(c,distances[b][a]);
        }

        rep(i,1,n){
            rep(j,1,n){
                if(distances[i][j]!=LLONG_MAX)graph[i].pb({j,distances[i][j]});
            }
        }


        while(q--){
            int a,b;
            cin >> a >> b;
            if(a==b){
                cout << "0\n";
                continue;
            }
            if(levels[a][b]!=LLONG_MAX){
                cout << levels[a][b] << "\n";
                continue;;
            }
            if(levels[b][a]!=LLONG_MAX){
                cout << levels[b][a] << "\n";
                continue;
            }
            djikstra(a);
            cout << levels[a][b] << "\n";
        }

    }

    return 0;}