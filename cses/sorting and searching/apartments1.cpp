#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);
 
    int n,m,k;
    cin >> n >> m >> k;
 
    int desire[n],apartment[m];
    rp(i,0,n)cin >> desire[i];
    rp(i,0,m)cin >> apartment[i];
 
    sort(desire,desire+n);
    sort(apartment,apartment+m);
 
    int i = 0, j = 0, ans = 0;
 
    while(i<n && j<m){
        int diff = abs(apartment[j]-desire[i]);
        if(diff<=k){
            ++j;
            ++i;
            ++ans;
        }
        else{
            if(abs(desire[i]-apartment[j])>k && desire[i]>apartment[j]){
                ++j;
            }
            else{
                ++i;
            }
        }
    }
 
    cout << ans << endl;
 
    return 0;}