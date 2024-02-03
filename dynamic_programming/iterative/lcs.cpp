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

int dp[3005][3005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string a="",b="",x,y;
    cin >> x >> y;

    int n = x.size();
    int m = y.size();
    a.pb('0');
    b.pb('0');

    rp(i,0,n)a.pb(x[i]);
    rp(i,0,m)b.pb(y[i]);

    rep(i,1,n){
        rep(j,1,m){
            if(a[i]==b[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
    }

    cout << dp[n][m] << " " << a << " " << b << "\n";

    string ans = "";
    int Size = dp[n][m];
    int i = 1, j = 1;

    while(Size>0 && i<=n && j<=m){
        if(a[i]==b[j]){
            ans.pb(a[i]);
            ++i;
            ++j;
            --Size;
        }
        else{
            if(dp[i+1][j]>=dp[i][j+1]){
                ++i;
            }
            else if(dp[i+1][j]<dp[i][j+1]){
                ++j;}
                // else{
                //     ++i;
                //     ++j;
                // }
            }
        }

    cout << ans << "\n";

    // rep(i,0,n){
    //     rep(j,0,m)cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    return 0;}

