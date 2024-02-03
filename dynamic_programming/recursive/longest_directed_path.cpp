/*
G - Longest Path  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There is a directed graph G with N vertices and M edges. The vertices are numbered 1,2,…,N, and for each i (1≤i≤M), the i-th directed edge goes from Vertex x 
i
​
  to y 
i
​
 . G does not contain directed cycles.

Find the length of the longest directed path in G. Here, the length of a directed path is the number of edges in it.

Constraints
All values in input are integers.
2≤N≤10^5
1≤M≤10^5
1≤xi,yi≤N
All pairs (xi,yi) are distinct.
G does not contain directed cycles.
Input
Input is given from Standard Input in the following format:

N M
x1 y1
x2 y2
:
xM yM​
 
Output
Print the length of the longest directed path in G.
Sample Input 1 
Copy
4 5
1 2
1 3
3 2
2 4
3 4
Sample Output 1 
Copy
3
The red directed path in the following figure is the longest:
Sample Input 2 
Copy
6 3
2 3
4 5
5 6
Sample Output 2 
Copy
2
The red directed path in the following figure is the longest:
Sample Input 3 
Copy
5 8
5 3
2 3
2 4
5 2
5 1
1 4
4 3
1 3
Sample Output 3 
Copy
3
The red directed path in the following figure is one of the longest:
*/

//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;

deq graph[100005];
int dp[100005];

int solve(int n){
    int ans = 0;

    if(dp[n]!=-1)return dp[n];

    rp(i,0,graph[n].size()){
        ans = max(ans,1+solve(graph[n][i]));
    }

    return dp[n]=ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp,-1,sizeof(dp));

    int n,m;
    cin >> n >> m;

    while(m--){
        int x,y;
        cin >> x >> y;
        graph[x].pb(y);
    }

    ll ans = 0;

    rep(i,1,n){
        ans = max(ans,solve(i));
    }

    cout << ans << '\n';

    return 0;}