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

int sparse[20][100005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    int arr[n+1] = {0};

    rep(i,1,n){cin >> arr[i];sparse[0][i] = arr[i];}

    for(int i = 1; (1<<i) <= n; i++){
        for(int j = 1; j <= (n+1-(1<<i)); j++){
            sparse[i][j] = min(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }

    // for(int i = 0; (1<<i) <= n; i++){
    //     for(int j = 1; j <= (n+1-(1<<i)); j++){
    //         cout << sparse[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int q;
    cin >> q;

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        int x = r-l+1, z = 0;

        // For Idempotent operations

        // while((1<<z)<=x){
        //     z++;
        // }
        // z--;
        // cout << z << " " << (1<<z) << "\n";
        // cout << sparse[z][l] << " " << sparse[z][r-(1<<z)+1] << "\n";
        // cout << min(sparse[z][l],sparse[z][r-(1<<z)+1]);

        int ans = LLONG_MAX;
        while((1<<z)<=x){
            if(((1<<z)&x)!=0){
                ans = min(ans,sparse[z][l]);
                cout << z << " " << (1<<z) << " " << sparse[z][l] << "\n";
                l+=(1<<z);
            }
            ++z;
        }

        cout << ans << "\n";

    }

    return 0;}