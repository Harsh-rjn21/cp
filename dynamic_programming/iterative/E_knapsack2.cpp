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

int dp[105][100005];

ll v[105],w[105],N,W;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> N >> W;
    ll sum = 0;
    rep(i,1,N){
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    for(int i = 1; i <=N;i++){
        for(int j = 1; j <= sum;j++){
            dp[i][j] = LLONG_MAX;
        }
    }
    dp[1][v[1]] = w[1];
    for(int i = 2; i <=N;i++){
        for(int j = 1; j <= sum;j++){
            dp[i][j] = dp[i-1][j];
            if((j-v[i])>=0 && dp[i-1][j-v[i]]!=LLONG_MAX){
                dp[i][j] = min(dp[i-1][j],w[i] + dp[i-1][j-v[i]]);
            }
        }
    }

    for(int i = sum; i>0; i--){
        for(int j = N; j >0;j--){
            if(dp[j][i]<=W){
                cout << i << "\n";
                return 0;
            }
        }
    }

    cout << "0\n";

    return 0;}