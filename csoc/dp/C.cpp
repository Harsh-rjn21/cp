#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
const int M = 2000000007;
const int m = 1000000004;
using namespace std;

int n;
int x[100005];
int h[100005];

int dp[100005][3];

// 0=> stay, 1=> left, 2=> right

int solve(int z,int remain_on_left,int prev){
    if(z>n)return 0;

    if(dp[z][prev]!=-1)return dp[z][prev];

    int ans = 0;

    if(remain_on_left>h[z]){
        ans = max(ans,1+solve(z+1,x[z+1]-x[z],1));
    }
    else{
    ans = max(ans,solve(z+1,x[z+1]-x[z],0));}

    if(x[z+1]>(h[z]+x[z]) || z==n){ans = max(ans,1+solve(z+1,x[z+1]-x[z]-h[z],2));}

    return dp[z][prev]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> n;


    for(int i = 1; i<=n; i++){
        cin >> x[i]>>h[i];
    }

    n == 1 ? cout<<"1\n" : cout << 1+solve(2,x[2]-x[1],1)<<"\n";

    return 0;}