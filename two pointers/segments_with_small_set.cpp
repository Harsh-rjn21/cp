/*Given an array of n integers ai. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good if there are no more than k unique elements on this segment. Your task is to find the number of different good segments.

Input
The first line contains integers n and k (1≤n≤105, 0≤k≤n). The second line contains integers ai (1≤ai≤105).

Output
Print one integer, the number of good segments.

Example
inputCopy
7 3
2 6 4 3 6 8 3
outputCopy
20
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,k;
    cin >> n >> k;
    ll a[n];

    rp(i,0,n)cin >> a[i];

    mii cnt;
    set<int> unique;
    int j = 0,ans=0;

    rp(i,0,n){
        unique.insert(a[i]);
        cnt[a[i]]++;
        while(unique.size()>k){
            cnt[a[j]]--;
            if(cnt[a[j]]==0){
                unique.erase(a[j]);
            }
            ++j;
        }
        ans+=(i-j+1);
    }

    cout << ans << "\n";

    return 0;}