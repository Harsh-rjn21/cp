/*
As the name says, this problem is about finding the number of points in a rectangle whose sides are parallel to axis. All the points and rectangles consist of 2D Cartesian co-ordinates. A point that lies in the boundary of a rectangle is considered inside.

Input
Input starts with an integer T (≤ 10), denoting the number of test cases.

Each case starts with a line containing an integer q (1 ≤ q ≤ 30000) denoting the number of queries. Each query is either one of the following:

0 x y, meaning that you have got a new point whose co-ordinate is (x, y). But the restriction is that, if a point (x, y) is already listed, then this query has no effect.
1 x1 y1 x2 y2, meaning that you are given a rectangle whose lower left co-ordinate is (x1, y1) and upper-right corner is (x2, y2); your task is to find the number of points, given so far, that lie inside this rectangle. You can assume that (x1 < x2, y1 < y2).
You can assume that the values of the co-ordinates lie between 0 and 1000 (inclusive).

Output
For each case, print the case number in a line first. Then for each query type (2), you have to answer the number of points that lie inside that rectangle. Print each of the results in separated lines.

Sample
Input	
1
9
0 1 1
0 2 6
1 1 1 6 6
1 2 2 5 5
0 5 5
1 0 0 6 5
0 3 3
0 2 6
1 2 1 10 10

Output
Case 1:
2
0
2
3
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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int fenwick[1007][1007],arr[1007][1007];

void update(int y,int z){
    for(int i = y; i<=1001;i+=(i & (-i))){
        for(int j = z; j<=1001; j+=(j&(-j))){
            fenwick[i][j]++;
        }
    }
}

int sum(int y,int z){
    int ans = 0;
    for(int i = y; i>0;i-=(i&(-i))){
        for(int j = z; j>0; j-=(j&(-j))){
            ans+=fenwick[i][j];
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    for(int tt= 1; tt<=t;tt++){

        memset(arr,0,sizeof(arr));
        memset(fenwick,0,sizeof(fenwick));
        cout <<"Case " << tt << ":\n";
        int q;
        cin >> q;

        while(q--){
            int x;
            cin >> x;

            if(x==0){
                int y,z;
                cin >> y >> z;
                if(arr[y+1][z+1]==0){
                    arr[y+1][z+1] = 1;
                    update(y+1,z+1);
                }
            }
            else if(x==1){
                int y1,z1,y2,z2;
                cin >> y1 >> z1 >> y2 >>z2;
                ll ans = sum(y2+1,z2+1) + sum(y1,z1) - sum(y1,z2+1) - sum(y2+1,z1); 
                cout << ans << "\n";
            }

        }
    }

    return 0;}