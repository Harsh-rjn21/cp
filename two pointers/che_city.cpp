/*This is a problem from the Russia High School Team Programming Contest 2013

In the center of Che city there is a pedestrian street, one of the most popular walking places for city residents. This street is very pleasant to walk, because along the street there are n funny monuments.

The girl Masha from the city of Che likes two boys from her school, and she cannot make a choice between them. To make the final decision, she decided to date both boys at the same time. Masha wants to choose two monuments on the pedestrian street, near which the boys will be waiting for her. At the same time, she wants to choose such monuments so that the boys do not see each other. Masha knows that because of the fog, the boys will see each other only if they are on distance not more than r meters. Masha got interested in how many ways there are to choose two different monuments for organizing dates.

Input
The first line of the input file contains two integers n and r (2≤n≤300000, 1≤r≤109), the number of monuments and the maximum distance at which boys can see each other.

The second line contains n positive numbers d1,…,dn, where di is the distance from the i-th monument to the beginning of the street. All monuments are located at different distances from the beginning of the street. Monuments are listed in ascending order of distance from the beginning of the street (1≤d1<d2<…<dn≤109).

Output
Print one number, the number of ways to choose two monuments for organizing dates.

Example
inputCopy
4 4
1 3 5 8
outputCopy
2
Note
In the given example, Masha can choose monuments 1 and 4 or monuments 2 and 4.*/

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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,r;
    cin >> n >> r;
    int arr[n];

    rp(i,0,n)cin >> arr[i];

    ll ans = 0;

    int i = 0;

    for(int j = 0; j < n; j++){
        while((arr[j]-arr[i])>r){
            ++i;
        }
        ans+=i;
    }

    cout << ans << "\n";

    return 0;}