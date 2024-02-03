#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int k;
// 1= white, 2 = red
int dp[100007][3];
int solve(int n,int prev){
    if(n==0)return 1;
    if(n<0)return 0;

    if(dp[n][prev]!=-1)return dp[n][prev];

    int ans= 0;
    if(n>=k){
    ans = (ans%M + 0LL + solve(n-k,1)%M)%M;}
    ans = (ans%M + 0LL + solve(n-1,2)%M)%M;
    return dp[n][prev] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t >> k;
    memset(dp,-1,sizeof(dp));

    deque<pii> test_cases;

    int a,b;

    int maxi = 0;

    for(int i = 0; i<t;i++){
        cin >> a >> b;
        test_cases.push_back({a,b});
        maxi = max(maxi,b);
    }

    int ans[maxi+1],pre_sum[maxi+1];

    ans[0] = 0;
    pre_sum[0] = 0;

    for(int i = maxi; i>=1;i--){
        ans[i] = solve(i,0)%M;
    }

    for(int i = 1; i<=maxi; i++){
        pre_sum[i] = (pre_sum[i-1]%M + 0LL + ans[i]%M)%M;
    }

    for(int i = 0; i<t;i++){
        cout<<((pre_sum[test_cases[i].second]%M)-(pre_sum[test_cases[i].first-1]%M)+M)%M<<"\n";
    }

    return 0;}