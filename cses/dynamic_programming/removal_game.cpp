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

int n;
deque<int> arr;

int sets[5007][5007];
pii dp[5007][5007];

pii solve(int turn,int initial, int final){
    if(initial > final){
        return {0,0};
    }

    if(sets[initial][final]==1)return dp[initial][final];

    sets[initial][final] = 1;
    int x = arr[final];
    pii ans1 = solve((turn+1)%2,initial,final-1);
    int y = arr[initial];
    pii ans2 = solve((turn+1)%2,initial+1,final);

    return dp[initial][final] = (turn==0) ? max(make_pair(ans1.f+x,ans1.s),make_pair(ans2.f+y,ans2.s)) : min(make_pair(ans1.f,ans1.s+x),make_pair(ans2.f,ans2.s+y));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> n;

    rep(i,1,n){
        int x;
        cin >> x;
        arr.pb(x);
    }

    auto ans = solve(0,0,n-1);

    cout << ans.f << "\n";

    return 0;}