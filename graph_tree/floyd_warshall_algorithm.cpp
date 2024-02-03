#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int dist[100][100];
deque<pair<int,int>> graph[100];
int distances[100];
bool visited[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dist, M, sizeof(dist));

    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        dist[a][b] = c;
    }

    for(int k = 1; k<=n;++k){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n;j++){
                if(i==j)dist[i][j] = 0;
                dist[i][j] = min(dist[i][j], (dist[i][k]+dist[k][j]));
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(dist[i][j] > 100)cout<<"M ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;}