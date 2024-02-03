#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int power(int a, int b){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<int> s;

    int n;
    cin>>n;

    for(int i = 1; i*i<=n;i++){
        if(n%i==0){s.insert(i);
            if(n/i!=i)s.insert(n/i);}
    }

    for(auto i : s)cout<<i<<" ";
    return 0;}