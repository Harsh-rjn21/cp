#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

ll binary_search(ll l, ll r, ll x, ll sz){
    ll mid = l + ((r-l)/2);
    if( x < mid )return binary_search(l,mid-1,x,sz-1);
    if(x > mid)return binary_search(mid+1,r,x,sz-1);
    return sz;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin >> n >> k;
    
    ll sz = 1;

    for(int i = 1; i < n; i++){
        sz = (2*sz) + 1;
    }

    cout << binary_search(1,sz,k,n);
    
    return 0;}