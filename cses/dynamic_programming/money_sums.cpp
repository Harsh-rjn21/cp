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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int dp[107][100007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    int arr[n+1] = {0};

    int sum = 0;
    rep(i,1,n){cin >> arr[i];sum+=arr[i];}
    rep(i,0,n){
        dp[i][0] = 1;
    }

    rep(i,1,n){
        rep(j,1,sum){
            dp[i][j] = dp[i-1][j];
            if(j-arr[i]>=0){
                dp[i][j] = max(dp[i-1][j-arr[i]],dp[i-1][j]);
            }
        }
    }

    deq ans;

    rep(i,1,sum){
        if(dp[n][i]==1){
            ans.pb(i);
        }
    }

    cout << sz(ans) << "\n";
    for(auto i : ans)cout << i << " ";
    return 0;}