/*
    Delete Edge!

Given a undirected tree with N nodes labeled  from 1 to N.

Each node has a certain weight assigned to it given by an integer array A of size N.

You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.

Return this maximum possible product modulo 109 + 7.

NOTE:

The tree is rooted at node labeled with 1.


Problem Constraints
2 <= N <= 105

1 <= A[i] <= 103



Input Format
First argument is an integer array A of size N denoting the weight of each node.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.



Output Format
Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.



Example Input
Input 1:

 A = [10, 5, 12, 6]
 B = [

        [1, 2]
        [1, 4]
        [4, 3]
     ]

Input 2:
 A = [11, 12]
 B = [[1, 2]]


Example Output
Output 1:
270
Output 2:
132


Example Explanation
Explanation 1:
 Removing edge (1, 4) created two subtrees.
 Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
 So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270

Explanation 2:
 Removing edge (1, 2) created two subtrees.
 Subtree-1 contains node (1) and Subtree-2 contains node (3)
 So product will be = (A[1]) * (A[2]) = 11 * 12 = 132
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

int weight[100];
deq tree_child[100];
map<int,int> relation;
int subtree_sum[100];

void sum(int index){
    if(tree_child[index].empty()){
        subtree_sum[index] = weight[index];
        return;
    }

    subtree_sum[index] = weight[index];

    for(auto i : tree_child[index]){
        if(subtree_sum[i] == 0){
            sum(i);
        }
        subtree_sum[index] += subtree_sum[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>weight[i];
    }
    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        tree_child[a].push_back(b);
        relation.insert({a,b});
    }

    sum(1);

    int ans = INT_MIN;
    pair<int,int> pans = {0,0};
    for(auto i : relation){
        int z = (subtree_sum[i.first] - subtree_sum[i.second]) * subtree_sum[i.second]; 
        if(z>ans){
            ans = z;
            pans = {i.first,i.second};
        }
    }
    cout<<ans<<" "<<pans.first<<" "<<pans.second<<"\n";
    return 0;}