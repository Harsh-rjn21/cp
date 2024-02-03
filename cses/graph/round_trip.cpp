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

deq graph[100007];
int visited[100007], parent[100007], Start, End;
bool ans = false;

void dfs(int n, int p){
    for(auto i : graph[n]){
        if(ans)break;
        if(visited[i]==1 && i!=p){
            ans = true;
            Start = n;
            End = i;
            break;
        }
        if(visited[i]==0){
            parent[i] = n;
            visited[i] = 1;
            dfs(i,n);
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

        rp(i,0,m){
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        rep(i,1,n){
            if(!ans && visited[i]==0){
                visited[i] = 1;
                dfs(i,0);
            }
        }

        if(!ans){
            cout << "IMPOSSIBLE" << "\n";
        }

        deq arr;
        int x = Start;
        arr.pb(x);
        while(x!=End){
            x = parent[x];
            arr.pb(x);
        }
        arr.pb(Start);
        cout<< sz(arr) << "\n";
        rp(i,0,sz(arr)){
            cout << arr[i] << " ";
        }
    }

    return 0;}