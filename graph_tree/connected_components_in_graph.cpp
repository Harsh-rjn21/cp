/*
    How to find connected components in graph.
    Connected components = Group of nodes such that unki kisi bi node se aap kisi bhi doosri node pr jaa sakte ho

Problem
Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in the graph. Calculate the total number of connected components in the graph. A connected component is a set of vertices in a graph that are linked to each other by paths.

Input Format:
First line of input line contains two integers n and e. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. 

Output Format:
For each input graph print an integer x denoting total number of connected components.

Constraints:
All the input values are well with in the integer range.

Sample Input
8 5
1 2
2 3
2 4
3 5
6 7

Sample Output
3
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

int components = 0;
bool visited[100007];
deq graph[100007];
deq connected_components[100007];
deq dfs;

void depth_first_search(int num){
    if(visited[num])return;
    else{
        visited[num] = true;
        connected_components[components].push_back(num);
        dfs.push_back(num);
        for(int i=0; i<graph[num].size(); i++){
            depth_first_search(graph[num][i]);
        }
    }
}

void solve(int num,int n){
    
    depth_first_search(num);
    components++;

    for(int i = 1; i<=n;i++){
        if(!visited[i]){
            depth_first_search(i);
            components++;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;

    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1,n);

    cout<<components<<"\n";

    for(int i=0;i<components;i++){
        for(auto j : connected_components[i]){
            cout<<j<<" "; 
        }
        cout<<"\n";
    }

    for(auto j : dfs)cout<<j<<" "; 

    return 0;}