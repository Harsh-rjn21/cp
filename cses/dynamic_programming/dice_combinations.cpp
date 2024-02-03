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
// int dp[7][1000007];
int dp[1000007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;


    // rep(i,0,6){
    //     dp[i][0] = 1;
    // }

    // rep(i,1,6){
    //     rep(j,1,n){
    //         dp[i][j]=dp[i-1][j];
    //         if(j-i>=0){
    //             dp[i][j]+=dp[i][j-i];
    //         }
    //     }
    // }

    // cout << dp[6][n] << endl;

    dp[0] = (1%M);

    rep(i,1,n){
        rep(j,1,6){
            if((i-j)<0)break;
            dp[i]=(dp[i]%M + dp[i-j]%M)%M;
        }
    }

    cout << dp[n]%M << "\n";

    return 0;}