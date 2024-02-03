#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

const ll n = 100005;
ll fact[n+1];

int main(){
    
    for(ll i =1 ; i<a.size();i++){
        fact[i] = fact[i-1]+a[i]-'0';
    }
    int l;
    int r;
    cin>>l>>r;
    ll ans = l==1 ? fact[r-1] : fact[r-1]-fact[l-2];
    cout<<ans;

    return 0;}