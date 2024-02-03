// Given two strings a and b. Calculate number of times a is present in b.

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

    string a,b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    string check = "";
    rp(i,0,n)check.pb(a[i]);
    check.pb(';');
    rp(i,0,m)check.pb(b[i]);

    cout << check << endl;

    int z[n+m+1];
    z[0] = 0;

    int left = 0, right = 0;

    rep(i,1,n+m){
        if(i<right){
            int k = i - left;
            if(i+z[k]<right){
                z[i] = z[k];
            }
            else{
                int x = 0,k = right - i,j=i;
                while(j<=n+m && k<=m+n && check[k]==check[j]){
                    ++x;
                    ++k;
                    ++j;
                }
                z[i] = x + right - i;
                left = i;
                right = j;
            }
        }
        else{
            int x = 0,j=i,k=0;
            while(j<=(n+m) && check[j]==check[k]){
                ++x;++k;++j;
                // cout << "h" << j << " " << k << " " << x << "\n";
            }
            // cout << i << " " << x << "\n";
            z[i] = x;
            right = j;
            left = i;
        }
    }

    // rep(i,0,n+m)cout << z[i] << " ";

    int ans = 0;
    rep(i,0,n+m){
        if(z[i]==n)ans++;
    }

    cout << ans << endl;

    return 0;}