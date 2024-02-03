#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

ll n;

bool check(ll k){
    ll vasya = 0, petya = 0;
    ll z = n;
    while(z>0){
        if((z < k) || (z < 10)){
            vasya+=z;
            z=0;
        }
        else{
            z-=k;
            vasya+=k;
        }
        if(z>=10){ll x = (z/10);
        z-=x;
        petya+=x;}
    }
    return (n%2)==0 ? (vasya >= (n/2)) : (vasya > (n/2));
}

ll func(ll low, ll high){

    while(high - low > 1){
        ll mid = (low+high)/2;
        if(check(mid)){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    if(check(low))return low;
    if(check(high)) return high;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cout << func(1,n);

    return 0;}