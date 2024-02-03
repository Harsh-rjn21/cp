/*
E. Turn Off The TV
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Luba needs your help again! Luba has n TV sets. She knows that i-th TV set will be working from moment of time li till moment ri, inclusive.

Luba wants to switch off one of TV sets in order to free the socket. Let's call some TV set redundant if after switching it off the number of integer moments of time when at least one of TV sets is working won't decrease. Luba will be very upset if she has to switch off a non-redundant TV set.

Help Luba by telling her the index of some redundant TV set. If there is no any, print -1.

Input
The first line contains one integer number n (1 ≤ n ≤ 2·105) — the number of TV sets.

Then n lines follow, each of them containing two integer numbers li, ri (0 ≤ li ≤ ri ≤ 109) denoting the working time of i-th TV set.

Output
If there is no any redundant TV set, print -1. Otherwise print the index of any redundant TV set (TV sets are indexed from 1 to n).

If there are multiple answers, print any of them.

Examples
inputCopy
3
1 3
4 6
1 7
outputCopy
1
inputCopy
2
0 10
0 10
outputCopy
1
inputCopy
3
1 2
3 4
6 8
outputCopy
-1
inputCopy
3
1 2
2 3
3 4
outputCopy
2
Note
Consider the first sample. Initially all integer moments of time such that at least one TV set is working are from the segment [1;7]. It's easy to see that this segment won't change if we switch off the first TV set (or the second one).

Note that in the fourth sample you can switch off the second TV set, since even without it all integer moments such that any of the TV sets is working denote the segment [1;4].
*/

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
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

    int t = 1;
    cin >> t;

    while(t--){

        

    }

    return 0;}