#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    deq a(n);
    mii cnt,ans;
    set ele;

    rp(i, 0, n)
    {
        cin >> a[i];
        // ele.insert(ele);
        ans[a[i]]=a[i];
        cnt[a[i]]++;
    }

    sort(all(a));

    int x = 2;
    if(!cnt.count(1)){
        cout << "1\n";
        return 0;
    }

    ans[1] = 1;
    while (true)
    {
        int z = x;
        if(!cnt.count(x)){
            ans[x] = ans[x-1];
            ans
        }
        ++x;
    }
    

    return 0;
}