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

bool check[8];
set<string> ans;
string l;
int n;

void solve(string a){
    if(a.size()==l.size()){
        ans.insert(a);
        return;
    }

    for(int i = 0; i < n; i++){
        if(check[i])continue;
        check[i] = true;
        string z = a;
        a.pb(l[i]);
        solve(a);
        check[i] = false;
        a = z;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> l;
    string a = "";
    n = l.size();

    solve(a);

    cout << ans.size() << "\n";

    for(auto i : ans){
        cout << i << "\n";
    }

    return 0;}