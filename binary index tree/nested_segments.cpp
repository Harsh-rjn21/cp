/*
Given an array of 2n numbers, each number from 1 to n in it occurs exactly twice. We say that the segment y is nested inside the segment x if both occurrences of the number y are between the occurrences of the number x. Find for each segment i how many segments that are nested inside it.

Input
The first line contains the number n (1≤n≤105), the second line contains 2n numbers. It is guaranteed that every number from 1 to n occurs exactly twice.

Output
Print n numbers, the i-th number is equal to the number of segments nested inside the segment i.

Example
inputCopy
5
5 1 2 2 3 1 3 4 5 4
outputCopy
1 0 0 0 3
*/

//							  ੴ  ਵਾਹਿਗੁਰੂ

// Approach => We store both indices of all the numbers.Then we arrange them in ascending order on basis of their right. Left pr inversion count approach laga do.

#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), c)
const ll M = 1000000007;
using namespace std;

int fenwick[400007];
pii positions[200007];

void update(int n, int N)
{
    for (int i = n; i <= N; i += (i & (-i)))
    {
        fenwick[i]++;
    }
}

int sum(int n)
{
    int ans = 0;
    for (int i = n; i > 0; i -= (i & (-i)))
    {
        ans += fenwick[i];
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    int arr[(2 * n) + 1];

    rep(i, 1, 2 * n)
    {
        int x;
        cin >> x;
        arr[i] = x;
        if (positions[x].f == 0)
        {
            positions[x].f = i;
        }
        else
        {
            positions[x].s = i;
        }
    }

    sort(positions, positions + n + 1, [](pii a, pii b)
         { return a.s < b.s; });

    ll ans[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        ans[arr[positions[i].f]] = (sum(2 * n) - sum(positions[i].f));
        update(positions[i].f, 2 * n);
    }

    rep(i, 1, n) cout << ans[i] << " ";

    return 0;
}