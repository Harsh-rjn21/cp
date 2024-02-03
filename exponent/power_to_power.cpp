/*
Euler Theorem : a^b^c=? then mod = 1e9+7(prime) ......
a^d =  a^b^c
then b^c % mod-1 and a^d % mod
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int power(int a, int b,int m){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%m * 1LL * a%m) % m;}
        a = (a%m * 1LL *a%m) % m;
        b >>= 1;}
    return ans;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    cin>>a>>b>>c;
    cout<<power(a,power(b,c,mod-1),mod);

    return 0;}