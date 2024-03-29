/*
    Method 2 => Using DFS and backtracking

Problem
Read problems statements in Mandarin Chinese and Russian.
Sometimes mysteries happen. Chef found a directed graph with N vertices and M edges in his kitchen!

The evening was boring and chef has nothing else to do, so to entertain himself, Chef thought about a question "What is the minimum number of edges he needs to reverse in order to have at least one path from vertex 1 to vertex N, where the vertices are numbered from 1 to N.

Input
Each test file contains only one test case.

The first line of the input contains two space separated integers N and M, denoting the number of vertices and the number of edges in the graph respectively. The ith line of the next M lines contains two space separated integers Xi and Yi, denoting that the ith edge connects vertices from Xi to Yi.

Output
In a single line, print the minimum number of edges we need to revert. If there is no way of having at least one path from 1 to N, print -1.

Constraints
1 ≤ N, M ≤ 100000 = 105
1 ≤ Xi, Yi ≤ N
There can be multiple edges connecting the same pair of vertices, There can be self loops too i.e. Xi = Yi
Sample 1:
Input
7 7
1 2
3 2
3 4
7 4
6 2
5 6
7 5
Output
2
Explanation:
We can consider two paths from 1 to 7:

1-2-3-4-7
1-2-6-5-7
In the first one we need to revert edges (3-2), (7-4). In the second one - (6-2), (5-6), (7-5). So the answer is min(2, 3) = 2.
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;

deque<pii> graph[100007];
mii answer;

void depth_first_search(int num, int target){
    
    if(num == target){    
        return;
    }

    for(auto i : graph[num]){
        if((!answer.count(i.first)) || (answer[i.first] > (i.second + answer[num]))){
        if(!answer.count(i.first)){
            answer.insert({i.first,i.second + answer[num]});
        }
        else{
            answer[i.first] = i.second + answer[num];
        }
            depth_first_search(i.first,target);
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back({b, 0});
        graph[b].push_back({a, 1});
    }

    depth_first_search(1,7);

    answer.count(n) ? cout << answer[n] << '\n' : cout << "-1\n";

    return 0;
}