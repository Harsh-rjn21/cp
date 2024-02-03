/*
NAKANJ - Minimum Knight moves !!!
Anjali and Nakul are good friends. They both had a quarrel recently while playing chess. Nakul wants to know the minimum number of moves a knight takes to reach from one square to another square of a chess board (8X8). Nakul is brilliant and he had already written a program to solve the problem. Nakul wants to know whether Anjali can do it. Anjali is very weak in programming. Help her to solve the problem.

A knight can move in the shape of an "L" in a chessboard - two squares either forward, backward, left, or right and then one square to its left or right. A knight move is valid if it moves as mentioned above and it is within the boundary of the chessboard (8 X 8).

Input
There are T test cases in total. The next T lines contain two strings (start and destination) separated by a space.

The strings start and destination will only contain two characters - First character is an alphabet between 'a' and 'h' (inclusive), Second character is a digit between '1' and '8' (inclusive) - (Quotes just for clarity).

To know the knight moves more clearly refer to the above figure.

Output
Print the minimum number of moves a knight takes to reach from start to destination in a separate line.

Constarints
1 <= T <= 4096

Example
Input:
3
a1 h8
a1 c2
h8 c3

Output:
6
1
4
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deque<pair<int, int>> chess[10][10];
bool visited[10][10];
map<pair<int, int>, int> levels;
int arr[8][2] = {
    {-2, -1}, {2, 1}, {-1, -2}, {1, 2}, {-2, 1}, {2, -1}, {-1, 2}, {1, -2}};

void solve(pair<int, int> start, pair<int, int> end)
{

    queue<pair<int, int>> bfs;
    visited[start.first][start.second] = true;
    levels.insert({start, 0});
    bfs.push(start);

    bool carry_on_jatta = true;

    while (bfs.front() != end && carry_on_jatta)
    {
        pair<int, int> z = bfs.front();
        for (int i = 0; i < 8; i++)
        {
            int x = z.first + arr[i][0], y = z.second + arr[i][1];
            if (x >= 1 && y >= 1 && x <= 8 && y <= 8)
            {
                pair<int, int> p = make_pair(x, y);
                visited[x][y] = true;
                levels.insert({p, 1 + levels[z]});
                bfs.push(p);
                if (p == end)
                {
                    carry_on_jatta = false;
                    break;
                }
            }
        }
        bfs.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        memset(visited, false, sizeof(visited));
        levels.clear();
        string x, y;
        cin >> x >> y;

        int sx = x[0] - 'a' + 1;
        int sy = x[1] - '1' + 1;
        int ex = y[0] - 'a' + 1;
        int ey = y[1] - '1' + 1;

        pair<int, int> start = {sx, sy};
        pair<int, int> end = {ex, ey};

        solve(start, end);

        cout << levels[end] << "\n";
    }

    return 0;
}