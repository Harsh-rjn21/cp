#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
// #define int long long
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

int n,m;

int dp[107][100007],arr[100007];

int solve(int index, int value){
    if(index==n && (arr[index]==0 || arr[index]==value)){
        return 1%M;
    }

    if(dp[value][index]!=-1)return dp[value][index];

    if(arr[index]!=0){
        if(value!=arr[index])return dp[value][index]=0;
    }

    int ans = 0;
    if(value>=1 && value<=m)ans = (ans%M + solve(index+1,value)%M)%M;
    if(value+1>=1 && value+1<=m)ans = (ans%M + solve(index+1,value+1)%M)%M;
    if(value-1>=1 && value-1<=m)ans = (ans%M + solve(index+1,value-1)%M)%M;
    return dp[value][index] = (ans%M);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp,-1,sizeof(dp));

    cin >> n >> m;

    rep(i,1,n)cin >> arr[i];

    int start = n+1;

    if(arr[0]!=0){
        cout << solve(1,arr[0])%M<<"\n";
    }
    else{
        int ans = 0;
        rep(i,1,m){
            ans = (ans%M + solve(1,i)%M)%M;
        }
        cout << ans%M << "\n";
    }

    return 0;}