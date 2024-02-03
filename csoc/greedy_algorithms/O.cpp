#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;
// USING DP
int n;
deque<string> all;
int dp[200005];

string rev_erse(string a){
    string x = "";
    int n = a.length();
    for(int i = (n-1); i>=0; i--){
        x.push_back(a[i]);
    }
    return x;
}

int solve(string a, int index){
    if(a!="" && a==rev_erse(a))return 1;
    if(index==n)return 0;

    if(dp[index]!=-1)return dp[index];

    int ans = 0;

    ans|=solve(a,index+1);

    a += all[index];
    ans|=solve(a,index+1);

    return dp[index]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while(t--){
    memset(dp,-1,sizeof(dp));
    all.clear();

    cin >> n;

    string a;

    for(int i = 0; i < n; i++){
        cin >> a;
        all.push_back(a);
    }

    cout << solve("",0)<<"\n";
}
    return 0;}