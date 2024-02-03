/*
    Minium Spanning tree:
    To find a tree from a graph such that sum of weights of its edges is least.
    Logic => Edges ko sort karo, Fir Unko ascending order mein Daal daalkar tree banate jaao.
    Ek disjoint set union banao taaki tum loops ko avoid kr sako.

    Input:
    6 9
    5 1 4
    5 4 9
    4 1 1
    1 2 2
    2 4 3
    3 4 5
    2 3 3
    2 6 7
    3 6 8
    
    Output:
    1 => {4,1} {2,2} {5,4}
    2 => {1,2} {3,3} {6,7}
    3 => {2,3}
    4 => {1,1}
    5 => {1,4}
    6 => {2,7}
    17
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

set<pair<int,pair<int, int>>> graph;
deque<pii> tree[100];
int parent[100];
int size[100];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(parent[v] == v) return parent[v];

    return parent[v] = find(parent[v]);
}

void Union(int a,int b){
    int x = find(a), y = find(b);

    if(size[x]>size[y])swap(x,y);
    
    parent[x] = parent[y];
    size[y] += size[x];
    size[x] = size[y];
}

int graph_to_min_spanning_tree(){

    if(graph.size()==0){return 0;}

    auto i = *(graph.begin());
    int wt = i.first;
    int a = i.second.first;
    int b = i.second.second;

    int z = 0;

    if(parent[a]!=parent[b]){
        tree[a].push_back({b,wt});
        tree[b].push_back({a,wt});
        Union(a,b);
        z = wt;
    }
    graph.erase(i);
    return z + graph_to_min_spanning_tree();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;

    for(int i = 1; i<=n; i++){
        make(i);
    }

    for(int i = 0; i < k; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        graph.insert({wt,{a,b}});
    }
    
    int ans = graph_to_min_spanning_tree();

    for(auto i = 1; i<=n; i++){
        cout<<i<<" => ";
        for(auto j : tree[i]){
            cout<<"{"<<j.first<<","<<j.second<<"} ";
        }
        cout<<"\n";
    }
    cout<<ans;
    return 0;}