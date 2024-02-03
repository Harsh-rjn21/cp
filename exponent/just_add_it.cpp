/*
ZSUM - Just Add It
no tags 
For two given integers n and k find (Zn + Zn-1 - 2Zn-2) mod 10000007, where Zn = Sn + Pn and Sn = 1k + 2k + 3k + … + nk and Pn = 11 + 22 + 33 + … + nn.

Input
There are several test cases (≤ 10000). In each case two space separated positive integers n and k are given.
For last test case n and k are given as 0 0, which is not to be processed.

Constraints
1 < n < 200000000
0 < k < 1000000

Output
For each case print the asked value in separate line.

Example
Input:
10 3
9 31
83 17
5 2
0 0

Output:
4835897
2118762
2285275
3694
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 10000007;
int phi = 9988440;
using namespace std;

int power(int a, int b,int mod){
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

    int n,k;
    cin>>n>>k;

    ull ans = 0;
    int z = power(n,(n%phi),M);
    ans += z;
    ans%=M;
    
    z = power((n-1),((n-1)%phi),M);
    ans += (2*z);
    ans%=M;
    
    z = power(n,(k%phi),M);
    ans += (z);
    ans%=M;
    
    z = power((n-1),(k%phi),M);
    ans += (2*z);
    ans%=M;
   
    cout<<ans<<"\n";
    
    return 0;}