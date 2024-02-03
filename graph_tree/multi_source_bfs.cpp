/*
    Means => Ek hi graph ko multiple sources se traverse krna h.
        Har node ka level will br minimum of the levels found by all sources.

    PROBLEM:
Snakes and transition from Capitalism to Socialism
Problem
After a long duration of the painful, torturous and tumultuous periods of capitalism in Snakeland, now the snakes have decided to adopt socialism. The houses in Snakeland are arranged in a rectangular fashion of dimension n * m. The wealth of the snake in the house at cell (i, j) is given by a[i][j] rupees.

A bill has been passed for making a smooth transition from capitalism to socialism. At the end of each hour, the wealth of a snake will grow and will become equal to the highest wealth that its neighbor had (at the start of the hour). That is, consider the maximum wealth among its neighbors at the start of the hour, and this snake's wealth will become equal to that at the end of the hour. Note that this increase in wealth will happen simultaneously for each snake. Two houses are said to be neighbors of each other if they share a side or corner with each other. Find out the minimum number of hours required for this transition.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space separated integers: n, m.

Each of the next n lines contains m space separated integers. The j-th integer in the i-th row denotes a[i][j].

Output
For each test case output a single integer corresponding to the minimum number of hours required for the transition.

Constraints
1 ≤ T ≤ 4
1 ≤ n, m ≤ 500
1 ≤ a[i][j] ≤ 10^6
Example
Input
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2
Output
0
1
2

Explanation
Example 1. The wealth of all the snakes is already equal. So, no time is required for the transition.

Example 2. At the end of the first hour, the wealth of snakes at cells (1, 1), (2,1) and (1, 2) will change from 1 to 2. Then, the wealth of all the snakes becomes equal, and hence it required a total of 1 hour.

Example 3. At the end of the first hour, the distribution of wealth of Snakeland will be as given below:

2 2 2 2
2 2 2 2
1 2 2 2
After the end of the second hour, the wealth of all the snakes will be equal. So, the answer is 2.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

int arr[505][505];
bool visited[505][505] = {false};
int level[505][505]={0};
int trans[8][2] = {
    {1,0},{0,1},
    {-1,0},{0,-1},
    {1,1},{-1,-1},
    {1,-1},{-1,1}
};

void binary_first_search(int n,int m,int maxi){
    queue<pair<int, int>> q;

    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(maxi == arr[i][j]){
                q.push({i,j});
                visited[i][j] = true;
                }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int x1 = x + trans[i][0];
            int y1 = y + trans[i][1];

            if(x1>=1 && x1<=n && y1>=1 && y1<=m){
                if((!visited[x1][y1]) || (level[x1][y1] > (1 + level[x][y]))){
                    visited[x1][y1] = true;
                    level[x1][y1] = 1 + level[x][y];
                    q.push({x1,y1});
                }
            }

        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    int maxi = INT_MIN;

    for(int i=1;i<=n; i++){
        for(int j=1;j<=m; j++){
            cin >> arr[i][j];
        }
        maxi = max(maxi,(*max_element(arr[i]+1,arr[i]+m+1)));
    }
    cout<<"Maximum element = "<<maxi<<"\n";
    binary_first_search(n,m,maxi);

    int ans = INT_MIN;

    for(int i=1;i<=n; i++){
        ans = max(ans,(*max_element(level[i]+1,level[i]+m+1)));
    }

    cout<<"ANS = "<<ans<<"\n";

    for(int i = 0 ; i<=(n+1);i++){
        for(int j=0;j<=(m+1); j++){
            cout<<level[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;}