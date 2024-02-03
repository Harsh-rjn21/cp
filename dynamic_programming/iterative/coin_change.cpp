//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin>>n>>m;
    int a[n+1] = {0};

    rep(i,1,n)cin >> a[i];
    sort(a,a+n+1);
    int dp[m+1] ={0};

    for(int i = 1; i <=m ;i ++){
        dp[i] = INT_MAX;
    }

    rep(i,1,m){
        rep(j,1,n){
            if(i-a[j]<0)break;
            dp[i] = min(dp[i],1+dp[i-a[j]]);
        }
    }

    cout << dp[m] << "\n";

    return 0;}