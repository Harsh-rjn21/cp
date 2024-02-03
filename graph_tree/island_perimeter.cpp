/*
Island Perimeter
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4

Example 3:
Input: grid = [[1,0]]
Output: 4

Constraints:
row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/

// #include<bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define deq deque<int>
// #define mii map<int,int>
// #define pii pair<int,int>
// int M = 1000000007;
// using namespace std;

// int island[200][200];

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int m,n;
//     cin >> m >> n ;

//     for(int i = 1; i<=m; i++){
//         for(int j = 1; j<=n; j++){
//             cin >> island[i][j] ;
//         }
//     }

//     int moves[4][2] = {    {1,0},{0,1},{-1,0},{0,-1}    };

//     int ans = 0;

//     for(int i = 1; i<=m; i++){
//         for(int j = 1; j<=n; j++){
//             if(island[i][j]==1){for(int k = 0; k<4; k++){
//                 if(island[i+moves[k][0]][j+moves[k][1]] == 0)ans++;
//             }}
//         }
//     }

//     cout << ans;

//     return 0;}

// Using DFS

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int m,n;
int visited[200][200];
int dp[200][200];
int island[200][200];
int moves[4][2] = {    {1,0},{0,1},{-1,0},{0,-1}    };

int depth_first_search(int x,int y){
    if(island[x][y] == 0) return 0;

    if(dp[x][y] != -1) return dp[x][y];

    int ans = 0;

    for(int i = 0; i < 4; i++){
        int a = x + moves[i][0];
        int b = y + moves[i][1];

        if(island[a][b] == 0) ans++;
        else{
            if(visited[a][b] == 0){
                visited[a][b] = 1; ans += depth_first_search(a,b);}
        }
    }

    return dp[x][y] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    int x = 0 ,y = 0;
    cin >> m >> n;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            cin >> island[i][j] ;
            if((x == 0 || y == 0) && island[i][j] == 1){
                x = i,y = j;
            }
        }
    }

    visited[x][y] = 1;
    cout << depth_first_search(x,y);

    return 0;}