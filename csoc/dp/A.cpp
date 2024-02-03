#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int n;
int days[105];
//0=rest, 1=contest, 2=sports
int dp[105][3];
int solve(int x,int prev){
    if(x>n)return 0;
    
    if(dp[x][prev]!=-1)return dp[x][prev];
    int ans = INT_MAX;

    ans = min(ans,1+solve(x+1,0));
    if((days[x]==1 || days[x]==3) && prev!=1)ans=min(ans,solve(x+1,1));
    if((days[x]==2 || days[x]==3) && prev!=2)ans=min(ans,solve(x+1,2));
    return dp[x][prev]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));
    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> days[i];
    }

    cout << solve(1,0);

    return 0;}