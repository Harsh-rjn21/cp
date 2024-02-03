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

int parent[100005], Size[100005];

void Make(int n){
    parent[n] = n;
    Size[n] = 1;
}

int Find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int a,int b){
    int x = Find(a), y = Find(b);
    if(Size[x] < Size[y]){
        swap(x,y);
    }
    Size[x] += Size[y];
    parent[y] = x;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        rep(i,1,n){
            Make(i);
        }

        rep(i,1,m){
            int a,b;
            cin >> a >> b;
            Union(a,b);
        }

        set<int> parents;

        rep(i,1,n){
            parents.insert(Find(i));
        }

        cout << parents.size()-1 << "\n";
        auto itr1 = parents.begin(),itr2 = parents.begin();
        itr2++;

        while(itr2!=parents.end()){
            cout << *itr1 << " " << *itr2 << "\n";
            itr2++;
        }
    }

    return 0;}