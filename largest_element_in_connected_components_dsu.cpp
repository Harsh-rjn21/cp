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

int parent[100];

void make(int n){
    parent[n] = n;
}

int find(int n){
    if(parent[n]==n){
        return n;
    }
    return parent[n] = max(parent[n],find(parent[n]));
}

void Union(int x, int y){
    int a = find(x);
    int b = find(y);
    if(b>a)swap(a,b);
    parent[b] = a;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rep(i,1,n){
        make(i);
    }

    int m;
    cin >> m;

    while(m--){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    rep(i,1,n){
        cout << i << " " << find(i) << "\n";
    }
    
    return 0;}