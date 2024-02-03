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

    int n;
    cin >> n;
    int a[n];

    rp(i,0,n)cin >> a[i];

    int dp[n] = {0};
    for(int i = 0;i<n;i++)dp[i] = 1;

    for(int i = 0; i < n; i++){
        // dp[i] = dp[i-1];
        for(int j = 0 ; j < i; j++){
            if(a[i]>a[j]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }

    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans = max(ans,dp[i]);
        cout << dp[i] << " ";
    }

    cout << "\n" << ans << "\n";

    return 0;}