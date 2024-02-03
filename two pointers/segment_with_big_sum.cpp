/*Given an array of n integers ai. Let's say that the segment of this array a[l..r] (1≤l≤r≤n) is good if the sum of elements on this segment is at least s. Your task is to find the shortest good segment.

Input
The first line contains integers n and s (1≤n≤105, 1≤s≤1018). The second line contains integers ai (1≤ai≤109).

Output
Print one integer, the length of the shortest good segment. If there are no such segments, print −1.

Example
inputCopy
7 20
2 6 4 3 6 8 9
outputCopy
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,s;
    cin >> n >> s;
    int a[n],sum = 0;

    rp(i,0,n){cin >> a[i];sum+=a[i];}

    if(sum<s){cout<<"-1\n";return 0;}

    int r = 0, l = 0;
    int x = 0;
   
    ll ans = n;

    for(int j=0;j<n;j++){
        x+=a[j];
        while(x-a[l]>=s){
            x-=a[l];
            ++l;
        }
        if(x>=s)ans=min(ans,j-l+1);
    }   
    
    cout << ans << "\n";
    return 0;}