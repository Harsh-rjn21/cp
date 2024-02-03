/*
Greg and Graph
Greg has a weighed directed graph, consisting of n vertices. In this graph any pair of distinct vertices has an edge between them in both directions. Greg loves playing with the graph and now he has invented a new game:

The game consists of n steps.
On the i-th step Greg removes vertex number xi from the graph. As Greg removes a vertex, he also removes all the edges that go in and out of this vertex.
Before executing each step, Greg wants to know the sum of lengths of the shortest paths between all pairs of the remaining vertices. The shortest path can go through any remaining vertex. In other words, if we assume that d(i, v, u) is the shortest path between vertices v and u in the graph that formed before deleting vertex xi, then Greg wants to know the value of the following sum: 
Help Greg, print the value of the required sum before each step.

Input
The first line contains integer n (1 ≤ n ≤ 500) — the number of vertices in the graph.

Next n lines contain n integers each — the graph adjacency matrix: the j-th number in the i-th line aij (1 ≤ aij ≤ 105, aii = 0) represents the weight of the edge that goes from vertex i to vertex j.

The next line contains n distinct integers: x1, x2, ..., xn (1 ≤ xi ≤ n) — the vertices that Greg deletes.

Output
Print n integers — the i-th number equals the required sum before the i-th step.

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams of the %I64d specifier.

Examples
inputCopy
1
0
1
outputCopy
0 
inputCopy
2
0 5
4 0
1 2
outputCopy
9 0 
inputCopy
4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3
outputCopy
17 23 404 0 
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deq order;
deq answers;
int dist[501][501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>dist[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        order.push_front(x);
    }

    for(int k =0;k< order.size();k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                dist[i][j] = min(dist[i][j],(dist[order[k]][j] + dist[i][order[k]])); 
            }
        }
        int sum = 0;
        for(int i = 0; i<=k;i++){
            for(int j = 0; j<=k; j++){
                sum+=dist[order[i]][order[j]];
            }
        }
        answers.push_front(sum);
    }

    for(auto i : answers){
        cout<<i << " ";
    }

    return 0;}