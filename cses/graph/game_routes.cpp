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
deq graph[100007],graphr[100007];
int dp[100007];

int solve(int src){

    if(src==1){
        return 1;
    }
    
    if(dp[src]!=-1){
        return dp[src]%M;
    }

    int ans = 0;

    for(auto i : graphr[src]){
        ans = ((ans%M) + (solve(i)%M))%M;
    }

    return dp[src] = ans%M;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while(t--){

        cin >> n >> m;

        rep(i,1,m){
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
            graphr[b].pb(a);
        }

        dp[1] = 1;

        rep(i,0,n){
            dp[i] = -1;
        }

        cout << solve(n) << "\n";

    }

    return 0;}