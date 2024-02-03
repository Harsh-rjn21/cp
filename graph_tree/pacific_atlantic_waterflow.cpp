/*
Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Example 2:
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]

Constraints:
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int m,n;
int height[207][207];
int pacific[201][201];
int atlantic[201][201];
int pacific_moves[2][2] = {{-1,0},{0,-1}};
int atlantic_moves[2][2] = {{1,0},{0,1}};

int pacific_flow(int x, int y){
    if(x <= 0 || y <= 0) return 1;
    
    if(pacific[x][y] != -1) return pacific[x][y];

    int ans = 0;

    for(int i = 0; i <2; i++){
        int a = x + pacific_moves[i][0];
        int b = y + pacific_moves[i][1];

        if(height[a][b] <= height[x][y]){
            ans = pacific_flow(a, b);
        }
    }
    return pacific[x][y] = ans;
}

int atlantic_flow(int x, int y){
    if(x >= m || y >= n) return 1;
    
    if(atlantic[x][y] != -1) return atlantic[x][y];
    
    int ans = 0;

    for(int i = 0; i <2; i++){
        int a = x + atlantic_moves[i][0];
        int b = y + atlantic_moves[i][1];

        if(height[a][b] <= height[x][y]){
            ans = atlantic_flow(a, b);
        }
    }
    return atlantic[x][y] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(pacific,-1,sizeof(pacific));
    memset(atlantic,-1,sizeof(atlantic));

    cin >> m >> n;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> height[i][j];
        }
    }

    set<pii> answer;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(pacific_flow(i, j) && atlantic_flow(i, j)){
                answer.insert({(i-1),(j-1)});
            }
        }
    }

    for(auto i : answer){
        cout << i.first << " " << i.second << "\n";
    }    

    return 0;}