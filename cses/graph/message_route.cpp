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

deq tree[100007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while(t--){

        int n,m;
        cin >> n >> m;

        rp(i,0,m){
            int a,b;
            cin >> a >> b;
            tree[a].pb(b);
            tree[b].pb(a);
        }


        bool visited[n+1];
        int ans[n+1]={0};

        rep(i,0,n){visited[i] = false;ans[i]=0;}

        queue<int> bfs;
        bfs.push(1);
        visited[1] = true;
        ans[1] = 1;

        while(bfs.size()!=0){
            int x = bfs.front();
            for(auto i : tree[x]){
                if(!visited[i]){
                    visited[i]=true;
                    ans[i] = 1 + ans[x];
                    bfs.push(i);
                }
            }
            bfs.pop();
        }

        if(ans[n]==0){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << ans[n] << "\n";

        deq a;
        a.pb(n);
        while(n!=1){
            for(auto i:tree[n]){
                if(ans[i]==ans[n]-1){
                    a.pb(i);
                    n = i;
                }
            }
        }

        for(int i = sz(a)-1; i>=0;i--){
            cout << a[i] << " ";
        }

    }

    return 0;}