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

pii paths[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int visit[10][10];
int dp[9][9][1<<8][1<<8];

// void solve(int x, int y,int visitx,int visity){
//     if(x==7 && y==1){
//         ans++;
//         return;
//     }

//     rp(i,0,4){
//         if(visit[x+paths[i].f][y+paths[i].s]==0){
//             visit[x+paths[i].f][y+paths[i].s]=1;
//             // solve(x+paths[i].f,y+paths[i].s);
//             visit[x+paths[i].f][y+paths[i].s]=0;
//         }
//     }
// }

int solve(int x, int y, int visitx, int visity){
    if(x==7 && y==1){
        return 1;
    }

    if(dp[x][y][visitx][visity]!=-1){
        return dp[x][y][visitx][visity];
    }
    // cout << visitx << " " << visity << endl;

    int ans = 0;
    rp(i,0,4){
        int h = x+paths[i].f, k = y+paths[i].s;
        int p = (1<<h), q = (1<<k);
        if(h>=1 && h<=7 && k>=1 && k<=7 && (visit[h][k]==0)){
            visit[h][k] = 1;
            ans += solve(h,k,(visitx|p),(visity|q));
            visit[h][k] = 0;
        }
    }
    cout << x << " " << y << " " << visitx << " " << visity << " " << ans << endl;
    return dp[x][y][visitx][visity] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp,-1,sizeof(dp));

    visit[1][1] = 1;

    cout << solve(1,1,(1<<1),(1<<1)) << endl;
    

    return 0;}