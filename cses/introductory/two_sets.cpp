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

    int t = 1;
    // cin >> t;

    while(t--){

        int n;
        cin >> n;

        if((n%4)!=0 && ((n+1)%4)!=0){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        if((n%4)==0){
            cout << (n/2) << "\n";
            for(int i = 2; i<=n; i+=4){
                cout << i << " " << i + 1 << " ";
            }
            cout << "\n";

            cout << (n/2) << "\n";
            for(int i = 1; i<=n; i+=4){
                cout << i << " " << i + 3 << " ";
            }
            cout << "\n";
        }

        if((n+1)%4==0){

            bool check[n+1];

            rep(i,0,n)check[i] = false;
            
            cout << (n+1)/2 << "\n";
            for(int i = 1; i<=n; i+=4){
                cout << i << " " << i+1 << " ";
                check[i] = check[i+1] = true;
            }
            cout <<"\n";
            cout << (n - (n+1)/2) << "\n";
            for(int i = 1; i<=n; i++){
                if(!check[i]){
                    cout << i << " ";
                }
            }
        }

    }

    return 0;}