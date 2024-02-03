/*
    Disjoint set union:
        1) Make nodes
        2) Find nodes => finds parent of the group in which node is present
        3) Union => combine groups that is, root nodes ko join karna
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int parent[100];
int size[100];

void make(int v){
    parent[v] = v; // Since, abhi kisi bhi group mein nhi h OR single membered group jiska root vo khud hai
}

int find(int v){
    // int x = v;
    // while(x!=parent[x]){ // Since root node ka parent vo khud hota hai
    //     x = parent[x];
    // }
    // return x; 

    if(parent[v] == v)return v;
    else return parent[v] = find(parent[v]); // Path Compression Optimisation
}

void Union(int a,int b){
    int x = find(a), y = find(b);
    if(size[x]>size[y])
        swap(x,y);
        
        parent[x] = y;
        size[y] += size[x];                // Union By Size (Barre mein chhote ko daalo)
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i<=n; i++){
        make(i);
        size[i] = 1;
    }

    int m;
    cin >> m;

    for(int i = 1; i<=m; i++){
        int a,b;
        cin >>a >> b;
        Union(a,b);
    }

    set<int> roots;

    for(int i = 1; i<=n; i++){
        roots.insert(find(i));
    }

    cout<<"Number of Connected Components: "<<roots.size()<<endl;

    return 0;}