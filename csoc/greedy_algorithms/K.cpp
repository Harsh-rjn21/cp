#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    multiset<ll> all;
    ll n;
    cin >> n;

    ll arr[n];
    ll s = 0;

    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        all.insert(arr[i]);
        s+=arr[i];
        if(s<0){
            s -= (*(all.begin()));
            all.erase(all.begin());
        }
    }

    cout << all.size();

    return 0;}