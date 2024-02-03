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

    int n,sum;
    cin >> n >> sum;
    int a[n]={0};
    
    for(int i=0;i<n;i++)cin >> a[i];

    int dp[n+1][sum+1];

    for(int i = 0; i <=n;i++){
        for(int j = 0; j <= sum;j++)dp[i][j] = 0;
    }

    for(int i = 0; i<=n;i++)dp[i][0] = 1;

    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=sum;j++){
            dp[i][j]|=dp[i-1][j];
            if(j-a[i-1]>=0){
                dp[i][j]|=dp[i-1][j-a[i-1]];
            }
        }
    }

    cout << dp[n][sum]<<"\n";

    return 0;}