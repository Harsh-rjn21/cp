#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

ull dp[21];

ull fact(int n){
    if(n==1 || n==0) return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = n*fact(n-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int n;

    cin >> n;

    int x = n/2;

    ull comb = fact(n)/(fact(x)*fact(x));

    cout << (comb * fact(x-1)*fact(x-1))/2;

    return 0;}