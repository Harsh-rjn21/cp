#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;
const ll n = 100005;
ll fact[n+1];

int main(){
    fact[0]=1;
    fact[1]=1;

    for(ll i = 2; i <= n; i++){
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
    int z;
    cin>>z;
    cout<<fact[z];
    return 0;}