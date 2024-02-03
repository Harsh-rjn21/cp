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

int dp[507][507];

int solve(int n, int m){
    if(n==m){
        return 0;
    }

    if(dp[n][m]!=-1)return dp[n][m];

    int ans = INT_MAX;
    rp(i,1,n){
        ans = min(ans,1+solve(n-i,m)+solve(i,m));
    }
    rp(i,1,m){
        ans = min(ans,1+solve(n,m-i)+solve(n,i));
    }
    return dp[n][m] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp, -1, sizeof(dp));

    int n,m;
    cin >> n >> m;

    cout << solve(n,m) << "\n";

    return 0;}