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

    ll n;
    cin >> n;

    int primes[] = {2,3,5,7};  

    ll exc = 0,mul = (2*3*5*7);

    for(int i = 0; i < 4; i++){
        exc += (n/primes[i]);
        ll z = mul/primes[i];
        exc += (n/z);
    }

    for(int i = 0; i<4; i++){
        for(int j = i+1; j < 4; j++){
            exc -= (n/(primes[i]*primes[j]));
        }
    }

    exc -= (n/mul);

    cout << (n-exc) <<"\n";
     
    return 0;}