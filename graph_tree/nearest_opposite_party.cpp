/*
Nearest Opposite Parity

You are given an array a consisting of n integers. In one move, you can jump from the position i to the position i−ai (if 1≤i−ai) or to the position i+ai (if i+ai≤n).

For each position i from 1 to n you want to know the minimum the number of moves required to reach any position j such that aj has the opposite parity from ai (i.e. if ai is odd then aj has to be even and vice versa).

Input
The first line of the input contains one integer n (1≤n≤2⋅105) — the number of elements in a.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤n), where ai is the i-th element of a.

Output
Print n integers d1,d2,…,dn, where di is the minimum the number of moves required to reach any position j such that aj has the opposite parity from ai (i.e. if ai is odd then aj has to be even and vice versa) or -1 if it is impossible to reach such a position.

Example
inputCopy
10
4 5 7 6 7 5 4 4 6 4
outputCopy
1 1 1 2 -1 1 1 3 1 1 
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 100000007;
using namespace std;

int n;
int arr[200007];
int dp[200007][2];

int min_moves(int index,int parity){
    if(index <=0 || index >n)return M;
    if((arr[index]&1) != parity)return 0;

    if(dp[index][parity]!=-1)return dp[index][parity];

    int ans = M;

    if((index+arr[index]) <= n)ans = min(ans,1 + min_moves(index+arr[index], parity));
    if((index-arr[index]) > 0)ans = min(ans,1 + min_moves(index-arr[index], parity));

    return dp[index][parity] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        int ans = min_moves(i,(arr[i]&1));
        (ans>1000005) ? cout<<"-1 " : cout<<ans<<" ";
    }

    return 0;}