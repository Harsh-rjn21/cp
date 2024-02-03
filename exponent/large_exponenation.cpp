/*1) If ans overflows then it can be handled by taking % mod
2) But if the value of mod is very large, then this can't happen So, We go for binary multiplication
that is multiply ki jagah add krke multiplication lelo ], it is O(n)
3) */

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

//Overflow avoid karne ke liye, add krke multiplication ka answer nikaalna  
// eg: 2*13 => 2*(1101)2 So, b ko right shift kar rahe h, Jab (b & 1 == 1) h. Keval tab add kar rhe h power ke saath 
// But har loop mein single time ka addition value calculate krte jaa rhe h
ull binary_multiply(ull a, ull b){
    ull ans = 0;
    while (b > 0){
        if (b & 1){ans = (ans%mod  + a%mod) % mod;}
        a = (a%mod + a%mod) % mod;
        b >>= 1;}
    return ans;}

ull power(int a, int b){
    ull ans = 1;
    while (b > 0){
        if (b & 1){ans = binary_multiply(ans,a);}
        a = binary_multiply(a,a);
        b >>= 1;}
    return ans;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<power(2,13);

    return 0;}