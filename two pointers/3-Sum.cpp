/*
    Given an array of distinct numbers. Find number triplets such their sum is 0. in n^2
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    int a[n];
    rp(i,0,n)cin >> a[i];

    vector<pair<int,pii>> x;

    rp(i,0,n){
        rp(j,i+1,n){
            x.push_back({a[i]+a[j],{a[i],a[j]}});
        }
    }

    sort(a,a+n);
    sort(all(x));

    // rp(i,0,x.size()){
    //     cout << x[i].f <<" ";
    // }

    // cout <<"\n";

    // rp(i,0,n){
    //     cout << a[i] <<" ";
    // }

    // cout <<"\n";

    int r = n-1,l=0;
    int ans = 0;
    while(l<x.size() && r>=0){
        if((x[l].f+a[r])==0){
            if(x[l].s.f!=a[r] && x[l].s.s!=a[r])ans++;
            l++;
        }
        else if((x[l].f+a[r])<0){
            l++;
        }
        else if((x[l].f+a[r])>0){
            r--;
        }
    }

    cout << ans/3 << "\n";

    return 0;}