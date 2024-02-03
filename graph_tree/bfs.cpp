#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq tree[100];
bool visited[100];
deq bfs;
int level;
map<int,int> levels;

void breadth_first_search() // O(nodes+edges)
{

    queue<int> q;
    visited[1] = true;
    bfs.push_back(1);
    q.push(1);
    levels.insert({1,0});

    while (!q.empty())
    {   
        for (auto i : tree[q.front()])
        {
            if (!visited[i])
            {
                visited[i] = true;
                bfs.push_back(i);
                q.push(i);
                levels.insert({i,1+levels[q.front()]});
            }
        }
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
    }

    breadth_first_search();

    for (auto i : bfs)
    {
        cout << i << " ";
    }

    for(auto i : levels){
        cout<<"\n"<<i.first << " "<< i.second ;
    }
    return 0;
}