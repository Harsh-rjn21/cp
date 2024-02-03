//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    int happy[n+1][3],dp[n+1][3]={0};
    rep(i,1,n){
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
    }

    for(int i = 1; i<=n;i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]) + happy[i][j];
        }
    }

    ll ans = max(dp[n][0],dp[n][1]);
    ans = max(ans,dp[n][2]);

    cout << ans << "\n";

    return 0;}