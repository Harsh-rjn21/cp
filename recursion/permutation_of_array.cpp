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

bool chosen[100];
deq permutation;
int a[100];

void next_permutation(){
    if(permutation.size()==3){
        rp(i,0,3){
            cout << permutation[i]<<" ";
        }
        cout << "\n";
        return;
    }

    rp(i,0,3){
        if(chosen[i])continue;
        chosen[i] = true;
        permutation.pb(a[i]);
        next_permutation();
        chosen[i] = false;
        permutation.pop_back();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rp(i,0,n){
        cin >> a[i];
    }

    next_permutation();

    return 0;}