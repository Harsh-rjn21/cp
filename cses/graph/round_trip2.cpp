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

vector<int> graph[100007];
int visited[100007],stk[100007],parent[100007];
int Start,End;
bool ans = false;

void dfs(int src){
    stk[src] = 1;
    for(auto i : graph[src]){
        if(visited[i]==1 && stk[i]==1){
            ans = true;
            Start = src;
            End = i;
        }
        if(visited[i]==0){
            visited[i] = 1;
            parent[i] = src;
            dfs(i);
        }
    }
    stk[src] = 0;
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
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
        }

       rep(i,1,n){
            if(visited[i]==0 && ans==false){
                visited[i] = 1;
                dfs(i);
            }
        }

        if(!ans){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        // cout << Start << " " << End << "\n";

        // rep(i,1,n){
        //     cout << i << " " << parent[i] << "\n";
        // }

        deq cycle;
        int x = Start;
        cycle.pb(x);
        while(x!=End){
            x = parent[x];
            cycle.pb(x);
        }
        cycle.pb(Start);

        reverse(all(cycle));
        
        cout << sz(cycle) << "\n";
        for(auto i : cycle)cout << i << " ";
    }

    return 0;}