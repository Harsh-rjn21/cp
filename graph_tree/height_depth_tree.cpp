/*
    Find height and height of all nodes in the tree_child.

    tree_child_child deque => tree_child_child[a] = {b,c,d} then (b,c,d) are children of a.
    tree_child_parent array => tree_child_child[a] = b then b is parent of a.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq tree_child[100007];
int tree_parent[100007];
bool visited_for_height[100007];
bool visited_for_depth[100007];
map<int,int> height;
map<int,int> depth;

void height_filling(int num){

    if(tree_child[num].size()==0){
        visited_for_height[num] = true;
        height.insert({num,0});
        return ;
    }

    visited_for_height[num] = true;

    int high = INT_MIN;

    for(auto i : tree_child[num]){
        if(!visited_for_height[i]){
            height_filling(i);
        }
        high = max(high,1+height[i]);
    }

    height.insert({num,high});
}

void depth_filling(int num){

    if(tree_parent[num] == 0){
        depth.insert({num,0});
        visited_for_depth[num] = true;
        return;
    }

    visited_for_depth[num] = true;

    depth_filling(tree_parent[num]);

    int deep = 1 + depth[tree_parent[num]];
    depth.insert({num,deep});
}

void start_depth_filling(int n){
    for(int i = 1; i <= n; i++){
        if(tree_child[i].empty()){
            depth_filling(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m; i++){
        int parent,child;
        cin >> parent >> child;
        tree_child[parent].push_back(child);
        tree_parent[child] = parent;
    }

    height_filling(1);
    start_depth_filling(n);

   for(int i = 1; i<= n; i++){
    cout<<i<<" "<<height[i]<<" "<<depth[i]<<"\n";
   }

    return 0;}