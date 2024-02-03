#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deque<pair<int,int>> graph[100];
int distances[100];
bool visited[100];

void dijktsra_algorithm(int src){
    set<pii> bfs;
    bfs.insert({0,src});
    distances[src] = 0;

    while(bfs.size()!=0){
        pii z = *(bfs.begin());
        int dist = z.first;
        int parent = z.second;
        bfs.erase(bfs.begin());
        if(visited[parent])continue;
        visited[parent] = true;
        for(auto i : graph[parent]){
            int child = i.first;
            int wt = i.second;
            if((wt+dist)<distances[child]){
                distances[child] = wt + dist;
                bfs.insert({wt + dist,child});
            }
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
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back(make_pair(y,z));
    }
    memset(distances,100,sizeof(distances));
    int k;
    cin>>k;
    dijktsra_algorithm(k);

    for(int i = 1;i<=n;i++){
        cout<<i<<" "<<distances[i]<<"\n";
    }

    return 0;}