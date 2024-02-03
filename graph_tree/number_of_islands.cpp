/*
Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

int islands = 0;
int m,n;
int arr[301][301];
bool visited[301][301] = {false};

void traverse(int r, int c){
    if(arr[r][c]==0 || r <= 0 || c <= 0 || r>m || c>n) return;

    visited[r][c] = true;
    traverse(r-1, c);
    traverse(r, c-1);
    traverse(r+1, c);
    traverse(r, c+1);
}

void solve(int r,int c){
    traverse(r,c);
    islands++;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(arr[i][j] == 1 && visited[i][j] == false){
                traverse(i,j);
                islands++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;

    int r=0,c=0;
    bool set = true;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>arr[i][j];
            if(set && arr[i][j]==1){
                set = false;
                r=i;
                c=j;
            }
        }
    }

    if(r!=0 && c!=0)solve(r,c);

    cout<<islands;

    return 0;}