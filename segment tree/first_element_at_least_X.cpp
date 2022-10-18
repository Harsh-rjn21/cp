/*
In this task, you need to add to the segment tree the operation of finding the minimum index j such that a[j]≥x.

Input
The first line contains two integers n and m (1≤n,m≤100000), the size of the array and the number of operations. The next line contains n numbers ai, the initial state of the array (0≤ai≤109). The following lines contain the description of the operations. The description of each operation is as follows:

1 i v: change the item with index i to v (0≤i<n, 0≤v≤109).
2 x: find the minimum index j such that a[j]≥x. If there is no such element, print −1. Indices start from 0.
Output
For each operation of the second type, print the answer for the query.

Example
inputCopy
5 7
1 3 2 4 6
2 2
2 5
1 2 5
2 4
2 8
1 3 7
2 6
outputCopy
1
4
2
-1
3
*/

//							  ੴ  ਵਾਹਿਗੁਰੂ

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

int arr[100007], tree[400007];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int start, int end, int pos, int num)
{
    if (start == end)
    {
        arr[start] = num;
        tree[node] = num;
        return;
    }

    int mid = (start + end) / 2;
    if (pos <= mid)
    {
        update(2 * node, start, mid, pos, num);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, pos, num);
    }

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int start, int end, int x)
{
    if (start == end)
    {
        return start;
    }
    int mid = (start + end) / 2;
    if (tree[2 * node] >= x)
    {
        return query(2 * node, start, mid, x);
    }
    else
    {
        return query(2 * node + 1, mid + 1, end, x);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;

    rp(i, 0, n) cin >> arr[i];

    build(1, 0, n - 1);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos, num;
            cin >> pos >> num;
            update(1, 0, n - 1, pos, num);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            x > tree[1] ? cout << "-1\n" : cout << query(1, 0, n - 1, x) << "\n";
        }
    }

    return 0;
}