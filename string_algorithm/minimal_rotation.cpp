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

    string a;
    cin >> a;

    int n = a.size();

    map<char,int> code;
    set<char> letters;

    rp(i,0,n)letters.insert(a[i]);

    int x = 0;

    for(auto i : letters){
        code[i] = x;
        ++x;
    }

    rp(i,0,n){
        a.pb(a[i]);
    }

    int hash[2*n];
    hash[0] = code[a[0]];

    rp(i,1,2*n){
        hash[i] = ((x%M * hash[i-1]%M)%M + code[a[i]]%M)%M;
    }

    pair<int,pii> ans = {hash[n-1],{0,n-1}};

    cout << ans.f << " " << ans.s.f << " " << ans.s.s <<"\n";

    rep(i,1,n){
        int z = hash[i+n-1] - hash[i-1]*power(x,n,M);
        cout << z << " " << i << " " << i+n-1 << "\n";
        if(z>ans.f){
            ans = {z,{i,i+n-1}};
        }
    }

    cout << ans.f << "\n";

    rep(i,ans.s.f,ans.s.s){
        cout << a[i];
    }

    return 0;}