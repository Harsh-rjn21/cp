#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 100000000;
using namespace std;

int k1,k2;
int dp[101][101][11][11];

int solve(int n1,int n2,int foot,int horse){
    if(n1==0 && n2==0)return (1%M);

    int ans = 0;

    if(dp[n1][n2][foot][horse]!=-1)return dp[n1][n2][foot][horse];

    if(foot<k1 && n1>0){
        ans = ((ans%M) + (solve(n1-1,n2,foot+1,0)%M))%M;
    }

    if(horse<k2 && n2>0){
        ans = ((ans%M) + (solve(n1,n2-1,0,horse+1)%M))%M;
    }

    return dp[n1][n2][foot][horse]=(ans%M);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int n1,n2;
    cin >> n1 >> n2 >> k1 >> k2;

    cout<<(solve(n1,n2,0,0)%M);

    return 0;}