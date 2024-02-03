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

    int n,x;
    cin >> n >> x;

    pii a[n];

    rp(i,0,n){cin >> a[i].f;a[i].s = i+1;}

    sort(a,a+n);

    int i = 0, j = n-1;

    while(i<j){
        int k = x-a[j].f;
        if(k>a[i].f){
            ++i;
        }
        else if(k<a[i].f){
            --j;
        }
        else if(k==a[i].f){
            cout << a[i].s << " " << a[j].s <<"\n";
            break;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;}