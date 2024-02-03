// Array given h; You have to find minimum element in [0,r]
// Only Difference update krte time instead of sum minimum element ka operation lagega
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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int n;
int arr[100],fenwick[100];

void update(int N,int x){
    for(int i = N; i<=n; i+=(i&(-i))){
        fenwick[i] = min(fenwick[i],x);
    }
}

int solve(int N){
    ll ans = INT_MAX;
    for(int i = N; i>0; i-=(i&(-i))){
        ans = min(ans,fenwick[i]);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> n;

    memset(fenwick,M,sizeof(fenwick));

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        update(i,arr[i]);
    }
    for(int i=1;i<=n;i++){
        cout << fenwick[i]<<" ";
    }

    cout << "\n";

    for(int i = 1; i<=n; i++){
        cout << solve(i) << " ";
    }


    return 0;}