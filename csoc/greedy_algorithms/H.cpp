#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ull n,a,b;

        cin >> n >> a >> b;

        ull x[n+1],p[n+1];
        x[0] = 0,p[0]=0;
        for(ull i = 1; i <= n; i++){
            cin>>x[i];
            p[i] = x[i]+p[i-1];}

        ull ans = LLONG_MAX;

        for(int i = 0; i <= n; i++){
            ans = min(ans,(a*x[i])+b*(p[n]-p[i]-((n-i-1)*x[i])));
        }
        
        cout << ans<<"\n";
    }

    return 0;}