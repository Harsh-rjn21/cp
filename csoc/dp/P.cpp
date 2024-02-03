#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;

int main()
{

    int n;
    cin >> n;
    deq a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    mii dp;

    int ans = 0;
    int lst = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        dp[x] = dp[x - 1] + 1;
        if (ans < dp[x])
        {
            ans = dp[x];
            lst = x;
        }
    }

    deq res;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == lst)
        {
            res.push_back(i);
            --lst;
        }
    }
    reverse(res.begin(), res.end());

    cout << ans << "\n";

    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}