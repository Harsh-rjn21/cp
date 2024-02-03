/*

Lowest common ancestor = Two nodes ka sabse niche wala common ancestor


13 12
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq path_to_root[100007];
int tree_parent[100007];

int main(){

    //  LEARN BINARY UPLIFTING ALGORITHM FOR LCA

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m; i++){
        int parent,child;
        cin >> parent >> child;
        tree_parent[child] = parent;
    }

    for(int i = 1; i<=n;i++){
        path_to_root[i].push_front(i);
        int z = i;
        while(z != 1){
            z = tree_parent[z];
            path_to_root[i].push_front(z);
        }
    }

    int q;
    cout<<"Give number of queries = ";
    cin>>q;

    while(q--){
    
        int a,b;
        cin>>a>>b;

        int min_len = min(path_to_root[a].size(),path_to_root[b].size());

        int lca = -1;

        for(int i = 0; i < min_len;i++){
            if(path_to_root[a][i] == path_to_root[b][i]){
                lca = path_to_root[a][i];
                continue;
            }
            else break;
        }
        cout<<lca<<"\n";
    }

    return 0;}