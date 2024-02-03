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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,x;
    cin >> n >> x;

    int arr[n];
    rp(i,0,n)cin>> arr[i];

    pii dp[1<<n];
    dp[0] = {0LL,0LL};

    rp(i,1,(1<<n)){
        dp[i] = {INT_MAX,INT_MAX};
        rp(j,0,n){
            if((i&(1<<j))!=0){
                int h = i - (1<<j);
                pii z = dp[h];
                int t,w;
                if((z.s+arr[j])<=x){
                    w = z.s+arr[j];
                    t = z.f;
                }
                else{
                    w = arr[j];
                    t = z.f+1;
                }
                dp[i] = min(dp[i],{t,w});
            }
        }
    }

    int ans = dp[(1<<n)-1].f;
    ans += ((dp[(1<<n)-1].s) == 0) ? 0 : 1;
    cout << ans << "\n";

    return 0;}