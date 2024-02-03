/*
D. Shichikuji and Power Grid

Shichikuji is the new resident deity of the South Black Snail Temple. Her first job is as follows:

There are n new cities located in Prefecture X. Cities are numbered from 1 to n. City i is located xi km North of the shrine and yi km East of the shrine. It is possible that (xi,yi)=(xj,yj) even when i≠j.

Shichikuji must provide electricity to each city either by building a power station in that city, or by making a connection between that city and another one that already has electricity. So the City has electricity if it has a power station in it or it is connected to a City which has electricity by a direct connection or via a chain of connections.

Building a power station in City i will cost ci yen;
Making a connection between City i and City j will cost ki+kj yen per km of wire used for the connection. However, wires can only go the cardinal directions (North, South, East, West). Wires can cross each other. Each wire must have both of its endpoints in some cities. If City i and City j are connected by a wire, the wire will go through any shortest path from City i to City j. Thus, the length of the wire if City i and City j are connected is |xi−xj|+|yi−yj| km.
Shichikuji wants to do this job spending as little money as possible, since according to her, there isn't really anything else in the world other than money. However, she died when she was only in fifth grade so she is not smart enough for this. And thus, the new resident deity asks for your help.

And so, you have to provide Shichikuji with the following information: minimum amount of yen needed to provide electricity to all cities, the cities in which power stations will be built, and the connections to be made.

If there are multiple ways to choose the cities and the connections to obtain the construction of minimum price, then print any of them.

Input
First line of input contains a single integer n (1≤n≤2000) — the number of cities.

Then, n lines follow. The i-th line contains two space-separated integers xi (1≤xi≤106) and yi (1≤yi≤106) — the coordinates of the i-th city.

The next line contains n space-separated integers c1,c2,…,cn (1≤ci≤109) — the cost of building a power station in the i-th city.

The last line contains n space-separated integers k1,k2,…,kn (1≤ki≤109).

Output
In the first line print a single integer, denoting the minimum amount of yen needed.

Then, print an integer v — the number of power stations to be built.

Next, print v space-separated integers, denoting the indices of cities in which a power station will be built. Each number should be from 1 to n and all numbers should be pairwise distinct. You can print the numbers in arbitrary order.

After that, print an integer e — the number of connections to be made.

Finally, print e pairs of integers a and b (1≤a,b≤n, a≠b), denoting that a connection between City a and City b will be made. Each unordered pair of cities should be included at most once (for each (a,b) there should be no more (a,b) or (b,a) pairs). You can print the pairs in arbitrary order.

If there are multiple ways to choose the cities and the connections to obtain the construction of minimum price, then print any of them.

Examples
inputCopy
3
2 3
1 1
3 2
3 2 3
3 2 3
outputCopy
8
3
1 2 3 
0
inputCopy
3
2 1
1 2
3 3
23 2 23
3 2 3
outputCopy
27
1
2 
2
1 2
2 3
Note
For the answers given in the samples, refer to the following diagrams (cities with power stations are colored green, other cities are colored blue, and wires are colored red):

For the first example, the cost of building power stations in all cities is 3+2+3=8. It can be shown that no configuration costs less than 8 yen.

For the second example, the cost of building a power station in City 2 is 2. The cost of connecting City 1 and City 2 is 2⋅(3+2)=10. The cost of connecting City 2 and City 3 is 3⋅(2+3)=15. Thus the total cost is 2+10+15=27. It can be shown that no configuration costs less than 27 yen.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int amount;
int stations;
int power_station[100]; 
int cost_per_km[100];
int parent[100];
pii city[100];
set<pair<int,pair<int,int>>> graph;
map<int,pii> check;
deque<pii> tree;

void make(int v){
    parent[v] = v;
}

int find(int a){
    if(parent[a] == a)return a;
    return parent[a] = find(parent[a]);
}

void Union(int child,int par){
    parent[child] = par;
}

void solve(){
    if(graph.size()==0)return;

    auto i = (*graph.begin());
    int a = i.second.first;
    int b = i.second.second;
    int wt = i.first;

    if(find(a)!=find(b)){
        int diffa = check.count(a) ? (wt - check[a].second) : (wt - power_station[a]);
        int diffb = check.count(b) ? (wt - check[b].second) : (wt - power_station[b]);

        if(diffb < diffa){
            swap(a,b);
            swap(diffa,diffb);
        }
        if(diffa < 0){
            Union(a,b);
            amount += diffa;
            if(check.count(a)){
                check[a] = {b,wt};
            }else{
                check.insert({a,{b,wt}});
            }
        }
    }
    graph.erase(i);
    solve();
}

//  In the solution, I have assumed -> Initially, all of the cities had a power station. Then I have to make a 
//  minimum spanning tree between the cities. where weight of each edge = cost of wire for that edge
//  Power Generator City = parent in the spanning tree
//  Check condition on making a wire (edge of minimum spanning tree) :-
//      1) cost of wire < cost of power stations
//      2) cost of wire < cost of wire to other city if laid previously

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x,y;
        cin >> x >> y;
        city[i] = {x,y};
    }


    for(int i = 1; i <= n; i++){
        cin >> power_station[i];
        amount+=power_station[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> cost_per_km[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int dist = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
            int cost = dist * (cost_per_km[j] + cost_per_km[i]);
            graph.insert({cost,{i,j}});
        }
    }

    for(int i = 1 ;i <= n; i++){
        make(i);
    }

    solve();

    set<int> ans;

    for(int i = 1; i <= n; i++){
        ans.insert(find(i));
    }

    cout<<"Power Stations = "<<ans.size()<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<"\nAmount = "<<amount<<endl;

    cout<<"Wires = "<<check.size()<<endl;
    for(auto i: check){
        cout<<i.second.first<<" "<<i.first<<"\n";
    }

    return 0;}