/*
    Diameter = Maximum distance between any two points in the tree
    Of cOurse, Those two points are going to be leaf nodes.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq tree_child[100007];
int tree_parent[100007];
map<int,int> height;
map<int,int> depth;

void height_filling(int num){
    
    if(tree_child[num].empty()){
        height.insert({num,0});
        return;
    }

    int high = INT_MIN;
    for(auto i : tree_child[num]){
        if(!height.count(i)){
            height_filling(i);
        }
        high = max(high,height[i]);
    }
    height.insert({num,1+high});
}
int diameter_by_height(int root){
    deq height_from_root;
    for(auto i : tree_child[root]){
        height_filling(i);
        height_from_root.push_back(height[i]+1); // height[i] = height of child of root; SO, corresponding height for root = (height[i] + 1)
    }

    sort(height_from_root.begin(), height_from_root.end());
    int z = height_from_root.size();
    return (height_from_root[z-1] + height_from_root[z-2]);
}
void depth_filling(int num){
    if(tree_parent[num]==0){
        depth.insert({num,0});
        return;
    }

    if(!depth.count(tree_parent[num]))depth_filling(tree_parent[num]);
    depth.insert({num,1+depth[tree_parent[num]]});
}

int diameter_by_depth(int n){
    deq depth_of_leaves;
    for(int i=1;i<=n;i++){
        if(tree_child[i].empty()){
            depth_filling(i);
            depth_of_leaves.push_back(depth[i]);
    }
}
    sort(depth_of_leaves.begin(), depth_of_leaves.end());
    int z = depth_of_leaves.size();
    return (depth_of_leaves[z-1]+depth_of_leaves[z-2]);
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

   int ans1 = diameter_by_depth(n);
   int ans2 = diameter_by_height(1);

   cout<<ans1<<" "<<ans2;

    return 0;}