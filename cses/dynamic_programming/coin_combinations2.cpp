#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
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

int dp[107][1000007];
int a[107];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,x;
    cin >> n >> x;

    rep(i,1,n)cin >> a[i];

    rep(i,0,100){
        dp[i][0] = 1%M;
    }

    rep(i,1,n){
        rep(j,1,x){
            dp[i][j] = dp[i-1][j]%M;
            if((j-a[i])>=0){
                dp[i][j] = (dp[i][j]%M + dp[i][j-a[i]]%M)%M;
            }
        }
    }

    cout << dp[n][x]%M << endl;

    return 0;}