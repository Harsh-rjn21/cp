/*
Sightseeing Trip
There is a travel agency in Adelton town on Zanzibar island. It has decided to offer its clients, besides many other attractions, sightseeing the town. To earn as much as possible from this attraction, the agency has accepted a shrewd decision: it is necessary to find the shortest route which begins and ends at the same place.
Your task is to write a program which finds such a route. In the town there are N crossing points numbered from 1 to N and M two-way roads numbered from 1 to M. Two crossing points can be connected by multiple roads, but no road connects a crossing point with itself. Each sightseeing route is a sequence of road numbers y1, …, yk, k > 2. The road yi (1 ≤ i ≤ k − 1) connects crossing points xi and xi+1, the road yk connects crossing points xk and x1. All the numbers x1, …, xk should be different. The length of the sightseeing route is the sum of the lengths of all roads on the sightseeing route, i.e. L(y1) + L(y2) + … + L(yk) where L(yi) is the length of the road yi (1 ≤ i ≤ k). Your program has to find such a sightseeing route, the length of which is minimal, or to specify that it is not possible, because there is no sightseeing route in the town.
Input
Input contains T tests (1 ≤ T ≤ 5). The first line of each test contains two integers: the number of crossing points N and the number of roads M (3 ≤ N ≤ 100; 3 ≤ M ≤ N · (N − 1)). Each of the next M lines describes one road. It contains 3 integers: the number of its first crossing point a, the number of the second one b, and the length of the road l (1 ≤ a, b ≤ N; a ≠ b; 1 ≤ l ≤ 300). Input is ended with a “−1” line.
Output
Each line of output is an answer. It contains either a string “No solution.” in case there isn't any sightseeing route, or it contains the numbers of all crossing points on the shortest sightseeing route in the order how to pass them (i.e. the numbers x1 to xk from our definition of a sightseeing route), separated by single spaces. If there are multiple sightseeing routes of the minimal length, you can output any one of them.
Sample
input	
5 7
1 4 1
1 3 300
3 1 10
1 2 16
2 3 100
2 5 15
5 3 20
4 3
1 2 10
1 3 20
1 4 30
-1
output
1 3 5 2
No solution.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deque<pii> graph[100];

int dijkstra_algorithm(int src,int n){
    int visited[100] = {0};
    set<pair<int,pii>> bfs;
    int distances[100] = {M};

    memset(distances,M,sizeof(distances));

    visited[src] = 1;

    for(auto i : graph[src]){
            int child = i.first;
            int wt = i.second;
                bfs.insert({wt,{child,src}});
                distances[child] = wt;
        }

    while(bfs.size()!=0){
        auto z = *(bfs.begin());
        int dist = z.first;
        int parent = z.second.first;
        int parent1 = z.second.second;
        bfs.erase(bfs.begin());
        if(visited[parent]==1)continue;
        visited[parent] = 1;
        for(auto i : graph[parent]){
            int child = i.first;
            int wt = i.second;
            if( (wt+dist) < distances[child] && child!=parent1){
                distances[child] = wt + dist;
                bfs.insert({(wt + dist),{child,parent}});
            }
        }
    }
    for(int i = 1; i<=n; i++){
        cout << i <<" " << distances[i] << endl;
    }
    return distances[src];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=0;i<m; i++){
        int a,b,wt;
        cin >> a >> b >> wt;
        graph[a].push_back({b,wt});
        graph[b].push_back({a,wt});
    }

    int ans = dijkstra_algorithm(1,n);

    return 0;}