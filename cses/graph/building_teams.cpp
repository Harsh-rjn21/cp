// Check Cycles in Graph

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

bool ans = true;
deq graph[100007];
int arr[100007];
int visited[100007];

void dfs(int src,int n){
    arr[src] = n;
    for(auto i : graph[src]){
        if(visited[i]==1){
            if(arr[i]==arr[src]){
                ans = false;
            }
            continue;
        }
        visited[i] = 1;
        dfs(i,(n+1)%2);
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

        int a,b;
        rp(i,0,m){
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        rep(i,1,n){
            if(visited[i]==0){
                visited[i] = 1;
                dfs(i,0);
            }
        }

        if(!ans){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        rep(i,1,n){
            cout << arr[i]+1 << " ";
        }

    }

    return 0;}