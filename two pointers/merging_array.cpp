/*
For educational purposes, in the problems of this block, the time limit is large enough for the solution to pass in O(nlogn) time, but try to write the solution in linear time, which we discussed in the lecture.

You are given two arrays, sorted in non-decreasing order. Merge them into one sorted array.

Input
The first line contains integers n and m, the sizes of the arrays (1≤n,m≤105). The second line contains n integers ai, elements of the first array, the third line contains m integers bi, elements of the second array (−109≤ai,bi≤109).

Output
Print n+m integers, the merged array.

Example
inputCopy
6 7
1 6 9 13 18 18
2 3 8 13 15 21 25
outputCopy
1 2 3 6 8 9 13 13 15 18 18 21 25 
*/

//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;
    ll a[n],b[m];

    rp(i,0,n)cin >> a[i];
    rp(i,0,m)cin >> b[i];

    int i = 0, j = 0;
    deq c;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(b[j]);
            j++;    
        }
    }

        while(i<n){
        c.push_back(a[i]);
        ++i;}

        while(j<m){
            c.push_back(b[j]);
            ++j;
        }

        rp(i,0,n+m)cout << c[i] << " ";

    return 0;}