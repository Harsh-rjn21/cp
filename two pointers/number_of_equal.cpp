/*You are given two arrays a and b, sorted in non-decreasing order. Find the number of pairs (i,j) for which ai=bj.

Input
The first line contains integers n and m, the sizes of the arrays (1≤n,m≤105). The second line contains n integers ai, elements of the first array, the third line contains m integers bi, elements of the second array (−109≤ai,bi≤109).

Output
Print one number, the answer to the problem.

Example
inputCopy
8 7
1 1 3 3 3 5 8 8
1 3 3 4 5 5 5
outputCopy
11*/
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;
    
    int a[n],b[m];

    rp(i,0,n)cin>> a[i];
    rp(i,0,m)cin>> b[i];

    ll ans = 0;
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            ll x = a[i],y = 0,z = 0;
            while(i<n && a[i]==x){
                ++i;++y;
                }
            while(j<m && b[j]==x){
                ++j;++z;
            }
            ans+=(y*z);
        }
        while(i<n && a[i]<b[j]){
            ++i;
        }
        while(j<m && a[i]>b[j]){
            ++j;
        }
        // cout << ans << endl;
    }

    cout << ans << endl;

    return 0;}