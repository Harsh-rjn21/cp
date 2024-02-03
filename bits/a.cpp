#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int power(int a, int b){
    int ans = 1;
    while (b > 0){
        if (b & 1){
            ans *= a;}
        a *= a;
        b >>= 1;}
    return ans;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll z = 1;

    cout << __builtin_clzll(z) <<"\n"; 

    return 0;}