/*
    Given n*n chess board, Tell number of permutations to place maximum number of queens in same board So that they don't kill each other.
*/

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

bool column[100],diagonal1[100],diagonal2[100];

int cnt,n;

// Approach => For
// n = 1, max queens = 1 , ans = 1
// n = 2, max queens = 1, ans = 4
// n = 3, max queens = 2, ans = 6
// n >= 4, max queens = n, ans = ??

void solve(int row){
    if(row == (n+1)){
        cnt++;
        return;
    }

    rep(i,1,n){
        if(column[i] || diagonal1[i+row] || diagonal2[i-row+n]){
            continue;
        }
        column[i] = diagonal1[i+row] = diagonal2[i-row+n] = true;
        solve(row+1);
        column[i] = diagonal1[i+row] = diagonal2[i-row+n] = false;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> n;

    if(n==1)cout << "1\n";
    else if(n==2)cout << "4\n";
    else if(n==3)cout << "6\n";
    else{
        solve(1);
        cout << cnt << "\n";
    }
    
    return 0;}