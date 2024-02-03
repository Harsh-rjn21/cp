/*
Problem Statement
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi. .

Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^9
1≤wi≤W
1≤vi≤10^3
 
Input
Input is given from Standard Input in the following format:

N W
w1 v1
​w2 v2
:
wN vN
​
 
Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1 
Copy
3 8
3 30
4 50
5 60
Sample Output 1 
Copy
90
Items 1 and 3 should be taken. Then, the sum of the weights is 3+5=8, and the sum of the values is 30+60=90.

Sample Input 2 
Copy
1 1000000000
1000000000 10
Sample Output 2 
Copy
10
Sample Input 3 
Copy
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Sample Output 3 
Copy
17
Items 2,4 and 5 should be taken. Then, the sum of the weights is 5+6+3=14, and the sum of the values is 6+6+5=17.
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

int N,W;
int dp[105][100005];
int w[105],v[105];
int solve(int index, int value){
    if(value==0)return 0;
    if(index>N && value!=0)return INT_MAX;

    if(dp[index][value]!=-1)return dp[index][value];

    return dp[index][value] = min(w[index]+solve(index+1,value-v[index]),solve(index+1,value));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp,-1,sizeof(dp));

    // int n,w;
    cin >> N >> W;

    int sum = 0;

    rep(i,1,N){cin >> w[i] >> v[i];sum+=v[i];}

    for(int i = sum; i >=0 ; i--){
        if(solve(1,i)<=W){
            cout << i;
            return 0;
        }
    }

    return 0;}