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

int num_of_digits(int n){
    int ans = 0;
    while (n!=0){
        ans++;
        n/=10;
    }
    return ans;
}

int dp[1000007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;   

    rep(i,1,n){
        dp[i] = INT_MAX;
        int z = i;
        while(z!=0){
            int x = z%10;
            if(i-x>=0 && x>0)dp[i] = min(dp[i],1LL+dp[i-x]);
            z/=10;
        }
    } 

    cout << dp[n] << "\n";

    return 0;}