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

    int h,w;
    cin >> h >> w;
    string a[h];

    rp(i,0,h)cin >> a[i];

    int dp[h][w];
    memset(dp,0,sizeof dp);
    dp[0][0] = (1%M);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j]!='#'){
                if((j-1)>=0){
                    dp[i][j] = (dp[i][j-1]%M + dp[i][j]%M)%M;
                }
                if((i-1)>=0){
                    dp[i][j]=(dp[i-1][j]%M+dp[i][j]%M)%M;
                }
            }
            else{
                dp[i][j] = (0%M);
            }
        }
    }

    // rp(i,0,h){
    //     rp(j,0,w)cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    cout << (dp[h-1][w-1]%M) << "\n";

    return 0;}