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

int visited[1005][1005],n,m,ans;
string a[1005];

void solve(int x,int y){
    if(x+1<n && visited[x+1][y]==0 && a[x+1][y]=='.'){
        visited[x+1][y] = 1;
        solve(x+1,y);
    }
    if(y+1<m && visited[x][y+1]==0 && a[x][y+1]=='.'){
        visited[x][y+1] = 1;
        solve(x,y+1);
    }
    if(x-1>=0 && visited[x-1][y]==0 && a[x-1][y]=='.'){
        visited[x-1][y] = 1;
        solve(x-1,y);
    }
    if(y-1>=0 && visited[x][y-1]==0 && a[x][y-1]=='.'){
        visited[x][y-1] = 1;
        solve(x,y-1);
    }
}

void dfs(){
    rp(i,0,n){
        rp(j,0,m){
            if(a[i][j]=='.' && visited[i][j]==0){
                visited[i][j]=1;
                solve(i,j);
                ans++;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

        cin >> n >> m;

        rp(i,0,n){
            cin >> a[i];
        }

        dfs();
        cout << ans << "\n";


    return 0;}