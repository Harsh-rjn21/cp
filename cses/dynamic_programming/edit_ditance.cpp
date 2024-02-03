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

string a,b;
int dp[5007][5007];

int solve(int ia,int ib){
    if(ia==sz(a) || ib==sz(b)){
        return abs(abs(sz(b)-ib)-abs(sz(a)-ia));
    }

    if(dp[ia][ib]!=-1)return dp[ia][ib];

    int ans = INT_MAX;

    if(a[ia]==b[ib]){
        ans = min(ans,solve(ia+1,ib+1));
    }
    else{
        ans = min(ans,1+solve(ia+1,ib+1));
    }

    ans = min(ans,1+solve(ia+1,ib));
    ans = min(ans,1+solve(ia,ib+1));
    return dp[ia][ib] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp,-1,sizeof(dp));

    cin >> a >> b;

    cout << solve(0,0);

    return 0;}