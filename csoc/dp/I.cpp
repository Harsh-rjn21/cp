#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int b[1000],c[1000];
int dp[10001][10001];
int **knap;

int min_moves(int start,int end){
    if(start==end)return 0;
    if(start>end)return M;

    if(dp[start][end]!=-1)return dp[start][end];
    int y = end - start;
    int z = 1;
    if(start%y!=0){
        z = (start/y) + 1;
    }
    else{
        z = start/y;
    }

    return dp[start][end] = (1 + min_moves(start+(start/z),end));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int t;
    cin >> t;  
   while(t--){ int n,k;

    cin >> n >> k;

    int moves = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        moves+=min_moves(1,b[i]);
    }
    ll coins = 0;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        coins += c[i];
    }

    k = min(k,moves);
    int knap[k+1] = {0};

    for(int i = 0;i<n;i++){
        for(int j = k - min_moves(1,b[i]);j>=0;j--){
            knap[j + min_moves(1,b[i])] = max(knap[j + min_moves(1,b[i])], knap[j] + c[i]);
        }
    }

    cout << *max_element(knap,knap+k+1)<<"\n";}

    return 0;}