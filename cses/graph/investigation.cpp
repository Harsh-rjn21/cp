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

int n,m;
vector<pii> graph[100007];
int distances[100007][4];
int visited[100007];

// 0 - distance, 3 - number, 1 - min flights, 2 - max flights

void djikstra(int src){
    set<tuple<int,int,int>> bfs;
    bfs.insert(make_tuple(0,src,0));

    while(sz(bfs)!=0){
        auto x = *(bfs.begin());
        int dist,parent,num;
        tie(dist,parent,num) = x;
        bfs.erase(bfs.begin());
        if(visited[parent]==1)continue;
        visited[parent] = 1;
        for(auto i : graph[parent]){
            int child = i.f,wt = i.s;
            if(distances[child][0]>wt+dist){
                distances[child][0] = wt+dist;
                distances[child][3] = distances[parent][3]%M;
                distances[child][1] = (distances[parent][1]%M+1%M)%M;
                distances[child][2] = (distances[parent][2]%M+1%M)%M;
                bfs.insert(make_tuple(wt+dist,child,num+1));
            }
            else if(distances[child][0]==(wt+dist)){
                distances[child][3] = (distances[child][3]%M+distances[parent][3]%M)%M;
                distances[child][1] = min((distances[parent][1]%M+1%M)%M,distances[child][1]);
                distances[child][2] = max((distances[parent][2]%M+1%M)%M,distances[child][2]);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> n >> m;
    rep(i,1,m){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].pb({b,c});
    }

    rep(i,0,n){
        distances[i][0] = LLONG_MAX;
        distances[i][1] = INT_MAX;
        distances[i][2] = INT_MIN;
    }
    distances[1][0] = 0;
    distances[1][3] = 1;
    distances[1][2] = 0;
    distances[1][1] = 0;
    djikstra(1);
    cout << distances[n][0] << " " << distances[n][3] << " " << distances[n][1] << " " << distances[n][2] << "\n";

    return 0;}