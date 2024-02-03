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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rep(i,1,n){
        if(i==1){
            cout << "0\n";
            continue;
        }
        if(i==2){
            cout << "6\n";
            continue;
        }
        if(i==3){
            cout << "28\n";
            continue;
        }
        if(i==4){
            cout << "96\n";
            continue;
        }
        int total = i*i;
        int ans = 0;
        ans+=4*(i*i-3);
        total-=4;
        ans+=8*(i*i-4);
        total-=8;
        ans+=(4*i-16)*(i*i-5);
        total-=(4*i-16);
        // ans+=(4*n-16)*(i*i-5);
        // total-=(4*n-16);
        ans+=4*(i*i-5);
        total-=4;
        ans+=(4*i-16)*(i*i-7);
        total-=(4*i-16);
        ans+=total*(i*i-9);
        cout << ans/2 <<"\n";
    }

    

    return 0;}