/*
 Longest Increasing Path in a Matrix
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 2^31 - 1
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int graph[100][100];
int m,n;
int moves[4][4] = {{1,0},{0,1},{-1,0},{0,-1}};
int dp[100][100];

int depth_first_search(int x,int y){
    
    if(dp[x][y]!=-1)return dp[x][y];

    int ans = 1;

    for(int i = 0; i < 4; i++){
        int a = x + moves[i][0], b = y+moves[i][1];
        if(a>=1 && a<=m && b>=1 && b<=n){
            if(graph[x][y]<graph[a][b]){
                ans = max(ans, 1 + depth_first_search(a,b));
            }
        }
    }

    return dp[x][y] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> m >> n;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=m; j++){
            cin >> graph[i][j];
        }
    }

    int ans = 1;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            ans = max(ans,depth_first_search(i,j));
        }
    }

    cout << ans;

    return 0;}