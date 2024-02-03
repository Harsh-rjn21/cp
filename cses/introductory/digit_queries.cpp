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
using namespace std;

int power(int a, int b){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans * 1LL * a);}
        a = (a * 1LL * a);
        b >>= 1;}
    return ans;}

int digits[18];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    rep(i,1,17){
        digits[i] = (i*power(10,i)) - ((power(10,i)-1)/9);
    }

    // rep(i,1,17)cout << digits[i] << "\n";

    while(t--){

        int n;
        cin >> n;
        int z = 0;
        rep(i,1,17){
            if(n>digits[i-1] && n<=digits[i]){
                z = i;
                break;
            }
        }
        // cout << z << endl;
        int x = (n - digits[z-1])%z==0 ? (n - digits[z-1])/z : (n - digits[z-1])/z + 1;
        int h = (n - digits[z-1])%z;
        int num = 0,y = 9;
        rp(i,0,z-1){
            num+=y;
            y*=10;
        }
        if(h==0){
            cout << (x+num)%10 <<"\n";
        }
        else{
            int k = z-h,p = x+num;
            while(k--){
                p/=10;
            }
            cout << p%10 <<"\n";
        }
    }

    return 0;}