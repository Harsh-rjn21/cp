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
    ll sum = 0;
    for(int i=0;i<n;i++){cin >> a[i];sum+=a[i];}

    if(sum&1){
        cout << "NO" << endl;
        return 0;
    }

    ll req = sum/2;

    int dp[n+1][req+1];

    rep(i,0,n){
        rep(j,0,req)dp[i][j] = 0;
    }

    rep(i,0,n)dp[i][0] = 1;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=req; j++){
            dp[i][j] |= dp[i-1][j];
            if(j-a[i-1]>=0){
                dp[i][j] |= dp[i-1][j-a[i-1]];
            }
        }
    }

    dp[n][req] == 1 ? cout << "YES" : "NO";

    return 0;}