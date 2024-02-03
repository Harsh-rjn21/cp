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

int dp[507][250507];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    if(!((n%4)==0 || (n+1)%4==0)){
        cout << "0\n";
        return 0;
    }

    int sum = n*(n+1)/4;

    rep(i,0,n){
        dp[i][0] = 1;
    }

    rep(i,1,n){
        rep(j,1,sum){
            dp[i][j] = (dp[i][j]%M + dp[i-1][j]%M)%M;
            if(j-i>=0)dp[i][j] = (dp[i][j]%M + dp[i-1][j-i]%M)%M;
        }
    }

    cout << (dp[n][sum]%M * modInverse(2,M)%M)%M << endl;

    return 0;}