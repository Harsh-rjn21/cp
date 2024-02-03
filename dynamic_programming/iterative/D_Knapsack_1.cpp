//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
using namespace std;

int N,W;
int dp[107][100007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> N >> W;

    int w[N+1],v[N+1];

    rep(i,1,N)cin >> w[i] >> v[i];

    for(int i=1;i<=N;i++){
        for(int j = 1; j<=W;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=w[i])dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }

    cout << dp[N][W] << "\n";

    return 0;}