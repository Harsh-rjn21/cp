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

string a[10];
int row[10], column[10], diag1[20], diag2[20];

int ans;

void solve(int n){
    if(n==9){
        ans++;
        return;
    }
    rep(i,1,8){
        if(row[n] || column[i] || diag1[i+n] || diag2[i-n+10] || a[n][i-1]=='*')continue;
        row[n] = column[i] = diag1[i+n] = diag2[i-n+10] = 1;
        solve(n+1);
        row[n] = column[i] = diag1[i+n] = diag2[i-n+10] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    rep(i,1,8){
        cin >> a[i];
    }

    solve(1);
    cout << ans << "\n";

    return 0;}