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

int dp[1007][1007];
string a[1007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rep(i,1,n)cin >> a[i];

    dp[1][1] = 1;

    rep(j,1,n){
        rep(i,1,n){
            if(a[i][j-1]=='.'){
                dp[i][j] = (dp[i][j]%M + dp[i-1][j]%M)%M;
                dp[i][j] = (dp[i][j]%M + dp[i][j-1]%M)%M;}
            if(a[i][j-1]=='*'){
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n][n] << "\n";

    return 0;}