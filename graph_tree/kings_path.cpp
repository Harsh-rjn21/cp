/*
King's Path

The black king is standing on a chess field consisting of 10^9 rows and 10^9 columns. We will consider the rows of the field numbered with integers from 1 to 10^9 from top to bottom. The columns are similarly numbered with integers from 1 to 10^9 from left to right. We will denote a cell of the field that is located in the i-th row and j-th column as (i, j).

You know that some squares of the given chess field are allowed. All allowed cells of the chess field are given as n segments. Each segment is described by three integers ri, ai, bi (ai ≤ bi), denoting that cells in columns from number ai to number bi inclusive in the ri-th row are allowed.

Your task is to find the minimum number of moves the king needs to get from square (x0, y0) to square (x1, y1), provided that he only moves along the allowed cells. In other words, the king can be located only on allowed cells on his way.

Let us remind you that a chess king can move to any of the neighboring cells in one move. Two cells of a chess field are considered neighboring if they share at least one point.

Input
The first line contains four space-separated integers x0, y0, x1, y1 (1 ≤ x0, y0, x1, y1 ≤ 109), denoting the initial and the final positions of the king.

The second line contains a single integer n (1 ≤ n ≤ 105), denoting the number of segments of allowed cells. Next n lines contain the descriptions of these segments. The i-th line contains three space-separated integers ri, ai, bi (1 ≤ ri, ai, bi ≤ 109, ai ≤ bi), denoting that cells in columns from number ai to number bi inclusive in the ri-th row are allowed. Note that the segments of the allowed cells can intersect and embed arbitrarily.

It is guaranteed that the king's initial and final position are allowed cells. It is guaranteed that the king's initial and the final positions do not coincide. It is guaranteed that the total length of all given segments doesn't exceed 105.

Output
If there is no path between the initial and final position along allowed cells, print -1.

Otherwise print a single integer — the minimum number of moves the king needs to get from the initial position to the final one.

Examples
inputCopy
5 7 6 11
3
5 3 8
6 7 11
5 2 5
outputCopy
4
inputCopy
3 4 3 10
3
3 1 4
4 5 9
3 10 10
outputCopy
6
inputCopy
1 1 2 10
2
1 1 3
2 6 10
outputCopy
-1
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
const int M = 1000000007;
using namespace std;

map<int, deq> allowed;
int moves[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
map<pii, int> levels;

bool check(int h, int k)
{
    bool ans = false;
    if (allowed.count(h))
    {
        for (int i = 0; i < allowed[h].size(); i += 2)
        {
            if (k >= allowed[h][i] && k <= allowed[h][i + 1])
            {
                ans = true;
                break;
            }
        }
    }
    return ans;
}

void breadth_first_search(int x1, int y1, int x2, int y2)
{
    queue<pii> bfs;
    bfs.push({x1, y1});

    levels.insert({{x1, y1}, 0});

    bool z = true;

    while (!bfs.empty() && z)
    {
        int x = bfs.front().first;
        int y = bfs.front().second;

        for (int i = 0; i < 8; i++)
        {
            int a = x + moves[i][0];
            int b = y + moves[i][1];
            if (check(a, b) && (!levels.count({a, b}) || levels[{a, b}] > (1 + levels[{x, y}])))
            {
                if (levels.count({a, b}))
                {
                    levels[{a, b}] = 1 + levels[{x, y}];
                }
                else
                {
                    levels.insert({{a, b}, 1 + levels[{x, y}]});
                }
                bfs.push({a, b});
                if(a == x2 && b == y2){
                    z = false;break;
                }
            }
        }
        bfs.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (allowed.count(a))
        {
            allowed[a].push_back(b);
            allowed[a].push_back(c);
        }
        else
        {
            deq z;
            z.push_back(b);
            z.push_back(c);
            allowed.insert({a, z});
        }
    }

    breadth_first_search(x1, y1, x2, y2);

    levels.count({x2, y2}) ? cout << levels[{x2, y2}] << "\n" : cout << "-1\n";

    return 0;
}