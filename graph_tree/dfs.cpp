#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq graph[100007];
deq dfs;
bool visited[100007];

void depth_first_search(int n) // O(nodes+edges)
{

    visited[n] = true;
    dfs.push_back(n);

    for (int i = 0; i < graph[n].size(); i++)
    {
        if (!visited[i])
            depth_first_search(graph[n][i]);
    }
}

void start_dfs(int num, int n)
{
    depth_first_search(num);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            depth_first_search(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // n = number of vertex, m = edges

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    start_dfs(1, n);

    for (auto i : dfs)
    {
        cout << i << " ";
    }

    return 0;
}