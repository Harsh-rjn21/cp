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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,k;
    cin >> n >> k;

    int h[n+1]={0};
    rep(i,1,n)cin >> h[i];

    int dp[n+1];
    dp[0]=0;dp[1]=0;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
        for(int j = 2;j<=k&&i-j>=1;j++){
            dp[i] = min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
        }
    }

    cout << dp[n] << "\n";

    return 0;}